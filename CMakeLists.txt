cmake_minimum_required(VERSION 3.20)

project(misis2024s-23-18-chashin-m-y)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "cmake")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG bin.dbg)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE bin.rel)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO bin.relwithdbg)

option(BUILD_WITH_CODEFORCES "Build prj.codeforces targets" off)

if (BUILD_WITH_CODEFORCES)
  add_subdirectory(prj.codeforces)
endif()

add_subdirectory(prj.lab)
add_subdirectory(prj.test)
add_subdirectory(prj.cw)