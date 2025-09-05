cmake_minimum_required(VERSION 4.0)
project(Physics_Engine)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Physics_Engine
        .idea/.gitignore
        .idea/modules.xml
        .idea/Physics_Engine.iml
        .idea/vcs.xml
        main.cpp
        main.h
        README.md)
