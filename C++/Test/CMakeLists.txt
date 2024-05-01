cmake_minimum_required(VERSION 3.20.0)
project(Test VERSION 0.1.0 LANGUAGES CXX)


set(wxWidgets_ROOT_DIR "C:/wxwidgets")
set(wxWidgets_LIB_DIR "C:/wxwidgets/lib/gcc810_x64_dll")

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})


file(GLOB project_GLOB
    scr/*
)

add_executable(Test ${project_GLOB})

target_link_libraries(Test ${wxWidgets_LIBRARIES})
target_include_directories(Test PRIVATE ${wxWidgerts_INCLUDE_DIRS})