#include <cstdint>
#include "hash_utils.hpp"
#include "file_utils.hpp"
#include <fstream>

namespace file_utils {
    std::vector<std::uint8_t> read_file(const std::string& filename) {
        std::ifstream file(filename, std::ios::binary);
        if (!file.is_open()) {
            return {};
        }
        
        std::vector<std::uint8_t> data((std::istreambuf_iterator<char>(file)),
                                       std::istreambuf_iterator<char>());
        return data;
    }

    bool write_file(const std::string& filename, const std::vector<std::uint8_t>& data) {
        std::ofstream file(filename, std::ios::binary);
        if (!file.is_open()) {
            return false;
        }
        
        file.write(reinterpret_cast<const char*>(data.data()), data.size());
        return true;
    }
}
