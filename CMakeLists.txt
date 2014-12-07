cmake_minimum_required (VERSION 2.6)
project (vcprompt2)

include_directories("${CMAKE_SOURCE_DIR}/include")

set(SOURCE "")
add_subdirectory(source)
add_subdirectory(unit-tests)

add_executable(vcprompt2 ${SOURCE})
