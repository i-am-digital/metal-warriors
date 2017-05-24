add_library(metal-source robot.cpp robot.h game.cpp game.h context.h window.h renderer.h surface.h texture.h)

if(${WIN32})
    target_include_directories(metal-source SYSTEM PRIVATE include)
    target_link_libraries(metal-source PUBLIC ${CMAKE_CURRENT_LIST_DIR}/lib/x86/SDL2.lib)
endif()

if(${UNIX})
    target_include_directories(metal-source SYSTEM PRIVATE ${SDL2_INCLUDE_DIR})
    target_link_libraries(metal-source PUBLIC ${SDL2_LIBRARY})
endif()

add_executable(metal-warriors main.cpp)
target_link_libraries(metal-warriors metal-source)
