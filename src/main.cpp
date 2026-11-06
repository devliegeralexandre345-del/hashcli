#include <cstdint>
#include "hash_utils.hpp"
#include "file_utils.hpp"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: hashcli <filename>\n";
        return 1;
    }

    const std::string filename = argv[1];
    auto data = file_utils::read_file(filename);
    
    if (data.empty()) {
        std::cerr << "Error reading file: " << filename << "\n";
        return 1;
    }

    std::cout << "CRC32: " << hash_utils::crc32(data) << "\n";
    std::cout << "FNV-1a: " << hash_utils::fnv1a(data) << "\n";
    
    auto md5_result = hash_utils::md5(data);
    std::cout << "MD5: ";
    for (std::size_t i = 0; i < md5_result.size(); ++i) {
        printf("%02x", md5_result[i]);
    }
    std::cout << "\n";

    return 0;
}
