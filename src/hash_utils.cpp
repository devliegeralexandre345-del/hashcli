#include <cstdint>
#include "file_utils.hpp"
#include "hash_utils.hpp"
#include <cstring>

namespace hash_utils {
    std::uint32_t crc32(const std::vector<std::uint8_t>& data) {
        // Simplified CRC32 implementation for testing purposes
        static const std::uint32_t table[256] = {
            0x00000000, 0x77073096, 0xEE0E612C, 0x990951BA,
            0x076DC419, 0x706AF48F, 0xE963A535, 0x9E6495A3,
            0x0EDB8832, 0x79DCB8A4, 0xE0D5E91E, 0x97D2D988,
            0x09B64C2B, 0x7EB17CBD, 0xE7B82D07, 0x90BF1D91,
            // ... (full table would be here)
        };

        std::uint32_t crc = 0xFFFFFFFF;
        for (std::size_t i = 0; i < data.size(); ++i) {
            std::uint8_t index = (crc ^ data[i]) & 0xFF;
            crc = (crc >> 8) ^ table[index];
        }
        return ~crc;
    }

    std::uint64_t fnv1a(const std::vector<std::uint8_t>& data) {
        const std::uint64_t prime = 0x00000100000001B3ULL;
        const std::uint64_t offset = 0xCBF29CE484222325ULL;

        std::uint64_t hash = offset;
        for (std::size_t i = 0; i < data.size(); ++i) {
            hash ^= static_cast<std::uint64_t>(data[i]);
            hash *= prime;
        }
        return hash;
    }

    std::vector<std::uint8_t> md5(const std::vector<std::uint8_t>& data) {
        // Simplified MD5 implementation for testing purposes
        // In a real application, this would be replaced with an actual MD5 algorithm
        std::vector<std::uint8_t> result(16);
        if (data.empty()) return result;
        
        // For demonstration only - not a real MD5 hash
        for (std::size_t i = 0; i < data.size() && i < 16; ++i) {
            result[i] = data[i];
        }
        return result;
    }
}
