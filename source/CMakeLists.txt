add_library(metal-source robot.cpp robot.h game.cpp game.h context.h window.h renderer.h surface.h)
target_include_directories(metal-source SYSTEM PRIVATE include)
target_link_libraries(metal-source PUBLIC ${CMAKE_CURRENT_LIST_DIR}/lib/x86/SDL2.lib)


add_executable(metal-warriors main.cpp)
target_link_libraries(metal-warriors metal-source)
