cmake_minimum_required(VERSION 3.14)

project(MyDrogonAppTests)

enable_testing()

find_package(GTest REQUIRED)

add_executable(test_palindrome test_palindrome.cpp ../palindrome.cpp)
target_include_directories(test_palindrome PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(test_palindrome PRIVATE Drogon::Drogon GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test_palindrome)