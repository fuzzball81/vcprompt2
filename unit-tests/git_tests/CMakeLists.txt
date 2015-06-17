include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runUnitTests
  interface_test.cpp
  ${CMAKE_SOURCE_DIR}/source/git.cpp)

# Standard linking to gtest stuff.
target_link_libraries(runUnitTests gtest gtest_main)
