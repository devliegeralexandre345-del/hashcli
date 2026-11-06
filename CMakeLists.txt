cmake_minimum_required(VERSION 3.16)
project(hashcli LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Threads REQUIRED)
include_directories(include)

file(GLOB_RECURSE ALL_SRCS CONFIGURE_DEPENDS "src/*.cpp")
set(LIB_SRCS ${ALL_SRCS})
list(FILTER LIB_SRCS EXCLUDE REGEX ".*main\\.cpp$")

add_executable(hashcli ${ALL_SRCS})
target_link_libraries(hashcli PRIVATE Threads::Threads)

enable_testing()
add_executable(unit_tests tests/test.cpp ${LIB_SRCS})
target_link_libraries(unit_tests PRIVATE Threads::Threads)
add_test(NAME AllTests COMMAND unit_tests)
