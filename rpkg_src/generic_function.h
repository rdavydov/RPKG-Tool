#pragma once
#include <string>

class generic_function
{
public:
	static void load_hash_list(bool exit_if_no_hash_list, std::string path = "");
	static std::string compute_ioi_hash(std::string& input_to_ioi_hash, bool outputRealMD5 = false);
	static void compute_ioi_hash_from_file(std::string& input_path);
	static void decrypt_packagedefinition_thumbs(std::string& input_path, std::string& output_path);
	static void encrypt_packagedefinition_thumbs(std::string& input_path, std::string& output_path);
};