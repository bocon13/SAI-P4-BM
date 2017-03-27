#ifndef SWITCH_META_DATA_H
#define SWITCH_META_DATA_H

#define NULL_HANDLE -1
#include  <sai.h>
#include <list>
#include <iostream>
#include <vector>
#include <map>
#include <standard_types.h>
#include "../inc/spdlog/spdlog.h"

using namespace bm_runtime::standard;

class sai_id_map_t { // object pointer and it's id
  protected:
    std::map<sai_object_id_t,void*> id_map;
    std::vector<sai_object_id_t> unused_id;
  public:
    sai_id_map_t(){
      // init
      unused_id.clear();
      id_map.clear();
    }

    ~sai_id_map_t(){
    }

    void free_id(sai_object_id_t sai_object_id){
      spdlog::get("logger")->debug("freeing object with sai_id {}",sai_object_id);
      delete id_map[sai_object_id];
      id_map.erase(sai_object_id);
      unused_id.push_back(sai_object_id);
    }

    sai_object_id_t get_new_id(void* obj_ptr){//pointer to object
      sai_object_id_t id;
      if(!unused_id.empty()){
        id = unused_id.back();
        unused_id.pop_back();
      }
      else { 
        id = id_map.size(); }
      id_map[id]=obj_ptr;
      return id;
    }

    void *get_object(sai_object_id_t sai_object_id) {
      return id_map[sai_object_id];
    }
};


class Sai_obj {
  public:
    sai_object_id_t sai_object_id;
    Sai_obj(sai_id_map_t* sai_id_map_ptr){
      sai_object_id = sai_id_map_ptr->get_new_id(this); // sai_id_map. set map to true.
    }
    ~Sai_obj(){
    }
  
};


class Port_obj : public Sai_obj{
  public:
    uint32_t hw_port;
    uint32_t l2_if;
    uint32_t pvid;
    uint32_t bind_mode;
    uint32_t mtu;
    uint32_t drop_tagged;
    uint32_t drop_untagged;
    bool is_lag;
    BmEntryHandle handle_lag_if;
    BmEntryHandle handle_port_cfg;
    BmEntryHandle handle_ingress_lag;
    Port_obj(sai_id_map_t* sai_id_map_ptr): Sai_obj(sai_id_map_ptr) {
      this->mtu=1512;
      this->drop_tagged=0;
      this->drop_untagged=0;
      this->hw_port=0;
      this->l2_if=0;
      this->pvid=1;
      this->bind_mode=SAI_PORT_BIND_MODE_PORT;
      this->is_lag=false;
      this->handle_ingress_lag = NULL_HANDLE;
      this->handle_port_cfg = NULL_HANDLE;
      this->handle_lag_if = NULL_HANDLE;
    }   
};

class BridgePort_obj : public Sai_obj {
public:
  uint32_t port_id;
  uint32_t vlan_id;
  uint32_t bridge_port;
  sai_bridge_port_type_t bridge_port_type;
  sai_object_id_t bridge_id;
  BmEntryHandle handle_id_1d;
  BmEntryHandle handle_id_1q;
  BmEntryHandle handle_egress_set_vlan;
  BmEntryHandle handle_egress_br_port_to_if;
  BmEntryHandle handle_subport_ingress_interface_type;
  BmEntryHandle handle_port_ingress_interface_type;
  BridgePort_obj(sai_id_map_t* sai_id_map_ptr) : Sai_obj(sai_id_map_ptr) {
    this->port_id=0;
    this->vlan_id=1;
    this->bridge_port=NULL;
    this->bridge_id=NULL;
    this->bridge_port_type=SAI_BRIDGE_PORT_TYPE_PORT;
    this->handle_id_1d =NULL_HANDLE;
    this->handle_id_1q =NULL_HANDLE;
    this->handle_egress_set_vlan =NULL_HANDLE;
    this->handle_egress_br_port_to_if =NULL_HANDLE;
    this->handle_subport_ingress_interface_type =NULL_HANDLE;
    this->handle_port_ingress_interface_type =NULL_HANDLE;

  }
};

class Bridge_obj : public Sai_obj {
public:
  sai_bridge_type_t bridge_type;
  std::vector<sai_object_id_t> bridge_port_list;
  uint32_t bridge_id;
  Bridge_obj(sai_id_map_t* sai_id_map_ptr) : Sai_obj(sai_id_map_ptr) {
    this->bridge_type=SAI_BRIDGE_TYPE_1Q;
    this->bridge_port_list.clear();
    this->bridge_id=1;
  }
};

class Vlan_obj : public Sai_obj {
  public:
    uint16_t vid;
    std::vector<sai_object_id_t> vlan_members;
    Vlan_obj(sai_id_map_t* sai_id_map_ptr) : Sai_obj(sai_id_map_ptr) {
      this->vlan_members.clear();
      this->vid = 0;
    }
};

class Vlan_member_obj : public Sai_obj {
  public:
    sai_object_id_t bridge_port_id;
    sai_object_id_t vlan_oid;
    uint32_t tagging_mode;
    uint16_t vid;
    BmEntryHandle handle_egress_vlan_tag;
    BmEntryHandle handle_egress_vlan_filtering;
    BmEntryHandle handle_ingress_vlan_filtering;
    Vlan_member_obj(sai_id_map_t* sai_id_map_ptr) : Sai_obj(sai_id_map_ptr){
      this->vid = NULL_HANDLE;
      this->vlan_oid = NULL_HANDLE;// TODO needed? consider remove.
      this->tagging_mode = SAI_VLAN_TAGGING_MODE_UNTAGGED;
      this->bridge_port_id=NULL_HANDLE;
    }
};

class Lag_obj : public Sai_obj {
public:
  uint32_t l2_if;
  std::vector<sai_object_id_t> lag_members;
  BmEntryHandle handle_lag_hash;
  BmEntryHandle handle_port_configurations;
  Port_obj* port_obj;
  Lag_obj(sai_id_map_t* sai_id_map_ptr) : Sai_obj(sai_id_map_ptr){
    this->lag_members.clear();
    this->l2_if=0;
    this->port_obj=NULL;
    this->handle_lag_hash=NULL_HANDLE;
    this->handle_port_configurations=NULL_HANDLE;
  }
};

class Lag_member_obj : public Sai_obj{
  public:
    Port_obj* port;
    Lag_obj* lag;
    BmEntryHandle handle_egress_lag;
    Lag_member_obj(sai_id_map_t* sai_id_map_ptr) : Sai_obj(sai_id_map_ptr){
      this->port=NULL;
      this->lag=NULL;
      this->handle_egress_lag = NULL_HANDLE;
  }
};

typedef std::map<sai_object_id_t, BridgePort_obj*>  bridge_port_id_map_t;
typedef std::map<sai_object_id_t, Port_obj*>        port_id_map_t;
typedef std::map<sai_object_id_t, Bridge_obj*>      bridge_id_map_t;
typedef std::map<sai_object_id_t, Vlan_obj*>        vlan_id_map_t;
typedef std::map<sai_object_id_t, Vlan_member_obj*> vlan_member_id_map_t;
typedef std::map<sai_object_id_t, Lag_obj*>         lag_id_map_t;
typedef std::map<sai_object_id_t, uint32_t>         l2_if_map_t;
typedef std::map<sai_object_id_t, Lag_member_obj*>  lag_member_id_map_t;
class Switch_metadata { // TODO:  add default.. // this object_id is the switch_id
public:
  sai_u32_list_t        hw_port_list;
  port_id_map_t         ports;
  bridge_port_id_map_t  bridge_ports;
  bridge_id_map_t       bridges;
  vlan_id_map_t         vlans;
  vlan_member_id_map_t  vlan_members;
  lag_id_map_t          lags;
  lag_member_id_map_t   lag_members;
  sai_object_id_t       default_bridge_id;
  Switch_metadata(){
    ports.clear();
    bridge_ports.clear();
    bridges.clear();
    vlans.clear();
    vlan_members.clear();
    lags.clear();
  }

  uint32_t GetNewBridgePort() {
    std::vector<uint32_t> bridge_port_nums;
    for (bridge_port_id_map_t::iterator it=bridge_ports.begin(); it!=bridge_ports.end(); ++it) {
      bridge_port_nums.push_back(it->second->bridge_port);
      spdlog::get("logger")->debug("{} ",it->second->bridge_port);
    }
    for (int i=0; i<bridge_port_nums.size(); ++i) {
      if (std::find(bridge_port_nums.begin(), bridge_port_nums.end(), i) == bridge_port_nums.end()) {
        spdlog::get("logger")->debug("-->GetNewBridgePort: bridge_port is: {} ", i);
        return i;
      }
    }
    spdlog::get("logger")->debug("--> GetNewBridgePort: bridge_port is: {} ", bridge_port_nums.size());
    return bridge_port_nums.size();
  }

  uint32_t GetNewBridgeID() {
    std::vector<uint32_t> bridge_ids;
    for (bridge_id_map_t::iterator it=bridges.begin(); it!=bridges.end(); ++it) {
      bridge_ids.push_back(it->second->bridge_id);
    }
    for (int i=0; i<bridge_ids.size(); ++i) {
      if (std::find(bridge_ids.begin(), bridge_ids.end(), i) == bridge_ids.end()) {
        return i;
      }
    }
    return bridge_ids.size();
  }
  uint32_t GetNewL2IF() {
    std::vector<uint32_t> l2_ifs_nums;
    for (port_id_map_t::iterator it=ports.begin(); it!=ports.end(); ++it) {
      l2_ifs_nums.push_back(it->second->l2_if);
    }
    for (lag_id_map_t::iterator it=lags.begin(); it!=lags.end(); ++it) {
      l2_ifs_nums.push_back(it->second->l2_if);
    }
    for (int i=0; i<l2_ifs_nums.size(); ++i) {
      if (std::find(l2_ifs_nums.begin(), l2_ifs_nums.end(), i) == l2_ifs_nums.end()) {
        spdlog::get("logger")->debug("--> Get_New_L2_if: new if is: {} ", i);
        return i;
      }
    }
    spdlog::get("logger")->debug("--> Get_New_L2_if: new if is: {} ", l2_ifs_nums.size());
    return l2_ifs_nums.size();
  }
};

#endif

