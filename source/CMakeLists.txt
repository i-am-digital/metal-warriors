add_library(metal-source robot.cpp robot.h)
target_include_directories(metal-source SYSTEM PRIVATE include)

add_executable(metal-warriors main.cpp)
target_link_libraries(metal-warriors metal-source)
