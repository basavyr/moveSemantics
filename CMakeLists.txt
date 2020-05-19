cmake_minimum_required(VERSION 3.0)

set(clang_path "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++")
set(clang++_path "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang")

set(cxx_standard 17)
set (project_title "Move-Semantics-C++")

project(${project_title})

set(CMAKE_CXX_STANDARD ${cxx_standard})
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# set(CMAKE_C_COMPILER "gcc-4.2")
# set(CMAKE_CXX_COMPILER "/usr/bin/g++-4.2")

#include all the headers from XCODE
include_directories($ENV{CPATH})

add_subdirectory(new_proj)