cmake_minimum_required(VERSION 4.0)
project(SortLab LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- GoogleTest ---
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.15.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


add_executable(SortLab main.cpp)
target_include_directories(SortLab PRIVATE src)


add_executable(tester tests/test.cpp)
target_include_directories(tester PRIVATE src)


target_link_libraries(tester PRIVATE GTest::gtest_main)


enable_testing()
include(GoogleTest)
gtest_discover_tests(tester)