cmake_minimum_required(VERSION 3.19)
project(Labirint_git)

set(CMAKE_CXX_STANDARD 14)
include_directories(C:/SFML-2.5.1/include)
include_directories(E:/OneDrive/Visual studio workspace/Libs/SFML-2.5.1/include)

add_executable(Labirint_git
        labirint/InfoImage.cpp
        labirint/Main.cpp
        labirint/Map.cpp
        labirint/Map.h
        labirint/Menu.cpp
        labirint/Menu.h
        labirint/Player.cpp
        labirint/Player.h
        labirint/View.cpp
        labirint/View.h)

