include(${gtest_SOURCE_DIR}/cmake/internal_utils.cmake)
#configure_compiler_and_linker()

add_executable(metal-warriors.tests
		firsttest.cpp)
target_link_libraries(metal-warriors.tests gtest gtest_main)