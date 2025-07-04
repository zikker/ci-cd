cmake_minimum_required(VERSION 3.14)
project(MyDrogonApp)

set(CMAKE_CXX_STANDARD 17)

find_package(Drogon CONFIG REQUIRED)

add_executable(MyDrogonApp main.cpp palindrome.cpp)
target_link_libraries(MyDrogonApp PRIVATE Drogon::Drogon)

enable_testing()
add_subdirectory(test)