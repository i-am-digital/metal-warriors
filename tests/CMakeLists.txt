include(${gtest_SOURCE_DIR}/cmake/internal_utils.cmake)
#configure_compiler_and_linker()

include_directories(SYSTEM ${gtest_SOURCE_DIR}/include)

add_executable(metal-warriors.tests
		robottests.cpp)
target_link_libraries(metal-warriors.tests metal-source gtest gtest_main)
