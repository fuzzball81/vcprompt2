cmake_minimum_required (VERSION 2.6)
project (vcprompt2)

set(SOURCE "")
add_subdirectory(source)

add_executable(vcprompt2 ${SOURCE})
