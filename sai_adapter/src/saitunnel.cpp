#include "sai_adapter.h"

sai_status_t sai_adapter::create_tunnel_map(
        _Out_ sai_object_id_t *tunnel_map_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list) {
    return SAI_STATUS_NOT_IMPLEMENTED;
}
       
sai_status_t sai_adapter::remove_tunnel_map(
        _In_ sai_object_id_t tunnel_map_id) {
    return SAI_STATUS_NOT_IMPLEMENTED;
}
       
sai_status_t sai_adapter::set_tunnel_map_attribute(
        _In_ sai_object_id_t tunnel_map_id,
        _In_ const sai_attribute_t *attr) {
    return SAI_STATUS_NOT_IMPLEMENTED;
}

sai_status_t sai_adapter::get_tunnel_map_attribute(
        _In_ sai_object_id_t tunnel_map_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list) {
    return SAI_STATUS_NOT_IMPLEMENTED;
}

sai_status_t sai_adapter::create_tunnel(
        _Out_ sai_object_id_t *tunnel_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list) {
    return SAI_STATUS_NOT_IMPLEMENTED;
}
       
sai_status_t sai_adapter::remove_tunnel(
        _In_ sai_object_id_t tunnel_id) {
    return SAI_STATUS_NOT_IMPLEMENTED;
}
       
sai_status_t sai_adapter::set_tunnel_attribute(
        _In_ sai_object_id_t tunnel_id,
        _In_ const sai_attribute_t *attr) {
    return SAI_STATUS_NOT_IMPLEMENTED;
}

sai_status_t sai_adapter::get_tunnel_attribute(
        _In_ sai_object_id_t tunnel_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list) {
    return SAI_STATUS_NOT_IMPLEMENTED;
}

sai_status_t sai_adapter::get_tunnel_stats(
        _In_ sai_object_id_t tunnel_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids,
        _Out_ uint64_t *counters) {
    return SAI_STATUS_NOT_IMPLEMENTED;
}

sai_status_t sai_adapter::get_tunnel_stats_ext(
        _In_ sai_object_id_t tunnel_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids,
        _In_ sai_stats_mode_t mode,
        _Out_ uint64_t *counters) {
    return SAI_STATUS_NOT_IMPLEMENTED;
}

sai_status_t sai_adapter::clear_tunnel_stats(
        _In_ sai_object_id_t tunnel_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids) {
    return SAI_STATUS_NOT_IMPLEMENTED;
}

sai_status_t sai_adapter::create_tunnel_term_table_entry(
        _Out_ sai_object_id_t *tunnel_term_table_entry_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list) {
    return SAI_STATUS_NOT_IMPLEMENTED;
}
       
sai_status_t sai_adapter::remove_tunnel_term_table_entry(
        _In_ sai_object_id_t tunnel_term_table_entry_id) {
    return SAI_STATUS_NOT_IMPLEMENTED;
}
       
sai_status_t sai_adapter::set_tunnel_term_table_entry_attribute(
        _In_ sai_object_id_t tunnel_term_table_entry_id,
        _In_ const sai_attribute_t *attr) {
    return SAI_STATUS_NOT_IMPLEMENTED;
}

sai_status_t sai_adapter::get_tunnel_term_table_entry_attribute(
        _In_ sai_object_id_t tunnel_term_table_entry_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list) {
    return SAI_STATUS_NOT_IMPLEMENTED;
}

sai_status_t sai_adapter::create_tunnel_map_entry(
        _Out_ sai_object_id_t *tunnel_map_entry_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list) {
    return SAI_STATUS_NOT_IMPLEMENTED;
}
       
sai_status_t sai_adapter::remove_tunnel_map_entry(
        _In_ sai_object_id_t tunnel_map_entry_id) {
    return SAI_STATUS_NOT_IMPLEMENTED;
}
       
sai_status_t sai_adapter::set_tunnel_map_entry_attribute(
        _In_ sai_object_id_t tunnel_map_entry_id,
        _In_ const sai_attribute_t *attr) {
    return SAI_STATUS_NOT_IMPLEMENTED;
}

sai_status_t sai_adapter::get_tunnel_map_entry_attribute(
        _In_ sai_object_id_t tunnel_map_entry_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list) {
    return SAI_STATUS_NOT_IMPLEMENTED;
}