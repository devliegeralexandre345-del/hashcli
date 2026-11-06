#pragma once
#include <cstdint>

#include <string>
#include <vector>

namespace file_utils {
    std::vector<std::uint8_t> read_file(const std::string& filename);
    bool write_file(const std::string& filename, const std::vector<std::uint8_t>& data);
}
