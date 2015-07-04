cmake_minimum_required (VERSION 2.6)
project (vcprompt2)

include(CTest)
include(CheckCXXCompilerFlag)

set(SOURCE "")
set(BUILD_CLAR OFF CACHE BOOL "Force disable of libgit2's CLAR testing")

CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
  message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

if(APPLE)
  set(CMAKE_MACOSX_RPATH ON)
  set(CMAKE_SKIP_BUILD_RPATH FALSE)
  set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
  set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
  set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
  list(FIND CMAKE_PLATFORM_IMPLICIT_LINK_DIRECTORIES "${CMAKE_INSTALL_PREFIX}/lib" isSystemDir)
  if("${isSystemDir}" STREQUAL "-1")
    set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
  endif()
endif()


add_subdirectory(source)
add_subdirectory(3rdParty/libgit2)

include_directories(${CMAKE_SOURCE_DIR}/include
  ${libgit2_SOURCE_DIR}/include)
set(LIBS ${LIBS} "git2")

add_subdirectory(unit-tests)

add_executable(${PROJECT_NAME} ${SOURCE})

target_link_libraries (${PROJECT_NAME} ${LIBS})
