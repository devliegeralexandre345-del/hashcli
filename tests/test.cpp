#include <iostream>
#include <vector>
#include <cstdint>
#include "hash_utils.hpp"
#include "file_utils.hpp"

void test_crc32() {
    // Corrected: Initialize vector with actual byte values instead of string literals
    std::vector<std::uint8_t> hello_data{static_cast<std::uint8_t>('h'), static_cast<std::uint8_t>('e'), 
                                         static_cast<std::uint8_t>('l'), static_cast<std::uint8_t>('l'), 
                                         static_cast<std::uint8_t>('o')};
    
    std::uint32_t crc = hash_utils::crc32(hello_data);
    // Expected CRC32 value for "hello" is 0x3610A686
    if (crc != 0x3610A686) {
        std::cout << "CRC32 test failed! Got: " << crc << ", expected: 0x3610A686\n";
        return;
    }
    std::cout << "CRC32 tests passed!\n";
}

void test_fnv1a() {
    // Corrected: Initialize vector with actual byte values instead of string literals
    std::vector<std::uint8_t> hello_data{static_cast<std::uint8_t>('h'), static_cast<std::uint8_t>('e'), 
                                          static_cast<std::uint8_t>('l'), static_cast<std::uint8_t>('l'), 
                                          static_cast<std::uint8_t>('o')};
    
    std::uint64_t fnv = hash_utils::fnv1a(hello_data);
    // Expected FNV-1a value for "hello" is 0x53D972C9
    if (fnv != 0x53D972C9) {
        std::cout << "FNV-1a test failed! Got: " << fnv << ", expected: 0x53D972C9\n";
        return;
    }
    std::cout << "FNV-1a tests passed!\n";
}

void test_md5() {
    // Corrected: Initialize vector with actual byte values instead of string literals
    std::vector<std::uint8_t> hello_data{static_cast<std::uint8_t>('h'), static_cast<std::uint8_t>('e'), 
                                          static_cast<std::uint8_t>('l'), static_cast<std::uint8_t>('l'), 
                                          static_cast<std::uint8_t>('o')};
    
    auto md5_result = hash_utils::md5(hello_data);
    // Expected MD5 for "hello" is 0x5D41402A
    if (md5_result.size() < 4 || md5_result[0] != 0x5D) {
        std::cout << "MD5 test failed!\n";
        return;
    }
    std::cout << "MD5 tests passed!\n";
}

void test_determinism() {
    // Corrected: Initialize vector with actual byte values instead of string literals
    const std::vector<std::uint8_t> data{static_cast<std::uint8_t>('a'), static_cast<std::uint8_t>('b'), 
                                          static_cast<std::uint8_t>('c'), static_cast<std::uint8_t>('d'), 
                                          static_cast<std::uint8_t>('e')};
    
    std::uint32_t crc1 = hash_utils::crc32(data);
    std::uint32_t crc2 = hash_utils::crc32(data);
    if (crc1 != crc2) {
        std::cout << "Determinism test failed!\n";
        return;
    }
    
    std::uint64_t fnv1 = hash_utils::fnv1a(data);
    std::uint64_t fnv2 = hash_utils::fnv1a(data);
    if (fnv1 != fnv2) {
        std::cout << "Determinism test failed!\n";
        return;
    }
    
    auto md5_result1 = hash_utils::md5(data);
    auto md5_result2 = hash_utils::md5(data);
    if (md5_result1 != md5_result2) {
        std::cout << "Determinism test failed!\n";
        return;
    }
    
    std::cout << "Determinism tests passed!\n";
}

int main() {
    test_crc32();
    test_fnv1a();
    test_md5();
    test_determinism();
    return 0;
}
