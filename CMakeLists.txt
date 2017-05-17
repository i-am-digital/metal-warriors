cmake_minimum_required(VERSION 2.8.7)
project(metal-warriors)

if(${UNIX})
    include(cmake/FindSDL2.cmake REQUIRED)
    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++14)
endif()

add_subdirectory(googletest)
add_subdirectory(tests)
add_subdirectory(source)
