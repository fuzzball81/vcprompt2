include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(testUtils
  util_test.cpp)

# Standard linking to gtest stuff.
target_link_libraries(testUtils gtest gtest_main)
add_test(UtilTests testUtils)
