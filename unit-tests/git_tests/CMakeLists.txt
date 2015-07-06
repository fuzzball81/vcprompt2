include_directories(
  ${gtest_SOURCE_DIR}/include
  ${gtest_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/unit-tests/mocks
)

add_executable(testGitInterface
  ${CMAKE_SOURCE_DIR}/unit-tests/mocks/git2.c
  ${CMAKE_SOURCE_DIR}/source/git.cpp
  interface_test.cpp
)

# Standard linking to gtest stuff.
target_link_libraries(testGitInterface gtest gtest_main)
add_test(GitInterfaceTest testGitInterface)
