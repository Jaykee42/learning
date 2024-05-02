cmake_minimum_required(VERSION 3.29.2 FATAL_ERROR)


set( CMAKE_CXX_COMPILER "C:/MinGW/bin/g++.exe" )
set( CMAKE_C_COMPILER "C:/MinGW/bin/gcc.exe" )

project(Test)

add_executable(Test src/main.cpp)