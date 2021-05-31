#include "global.h"

std::vector<rpkg> rpkgs;

int percent_progress = 0;

std::string response_string = "";

std::string timing_string = "";

std::vector<char> response_data;

std::string task_status_string = "";

int task_single_status = READY;

int task_multiple_status = READY;

int gui_control = READY;

std::string localization_string = "";

std::string hashes_with_no_reverse_depends = "";

std::string hash_direct_depends = "";

std::string hash_list_string = "";

std::vector<std::string> hashes_depends_map_rpkg_file_paths;

std::vector<std::map<uint64_t, uint64_t>> hashes_depends_map;

int hash_list_version = 0;

bool hash_list_loaded = false;

std::map<uint64_t, uint64_t> hash_list_hash_map;

std::vector<std::string> hash_list_hash_file_names;

std::vector<std::string> hash_list_hash_value_strings;

std::vector<std::string> hash_list_hash_strings;