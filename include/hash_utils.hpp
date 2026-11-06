#pragma once
#include <cstdint>
#include <string>
#include <vector>

namespace hash_utils {
    std::uint32_t crc32(const std::vector<std::uint8_t>& data);
    std::uint64_t fnv1a(const std::vector<std::uint8_t>& data);
    std::vector<std::uint8_t> md5(const std::vector<std::uint8_t>& data);
}
