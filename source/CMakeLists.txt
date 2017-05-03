add_library(metal-source robot.cpp robot.h)
add_executable(metal-warriors main.cpp)
target_link_libraries(metal-warriors metal-source)
