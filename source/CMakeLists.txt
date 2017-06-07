add_library(metal-source robot.cpp robot.h game.cpp game.h context.h window.h renderer.h surface.h texture.h bullet.h bullet.cpp target.h target.cpp)

if(${WIN32})
    target_include_directories(metal-source SYSTEM PRIVATE include)
    target_link_libraries(metal-source PUBLIC ${CMAKE_CURRENT_LIST_DIR}/lib/x86/SDL2.lib)
    file(COPY ${CMAKE_CURRENT_LIST_DIR}/lib/x86/SDL2.dll DESTINATION "${PROJECT_BINARY_DIR}/source")
endif()

if(${UNIX})
    target_include_directories(metal-source SYSTEM PRIVATE ${SDL2_INCLUDE_DIR})
    target_link_libraries(metal-source PUBLIC ${SDL2_LIBRARY})
endif()

add_executable(metal-warriors main.cpp)
target_link_libraries(metal-warriors metal-source)

file(COPY images/tank-sprite.bmp DESTINATION "${PROJECT_BINARY_DIR}/source")
file(COPY images/bullet.bmp DESTINATION "${PROJECT_BINARY_DIR}/source")
