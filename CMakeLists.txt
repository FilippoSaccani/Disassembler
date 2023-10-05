cmake_minimum_required(VERSION 3.21)
project(Disassembler)

set(CMAKE_CXX_STANDARD 23)

add_executable(Disassembler src/main.cpp src/tools/tools.h)
