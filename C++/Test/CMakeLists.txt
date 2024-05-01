cmake_minimum_required(VERSION 3.20.0)
project(Test VERSION 0.1.0 LANGUAGES CXX)

file(GLOB project_GLOB
    scr/*
)

add_executable(Test ${project_GLOB})


