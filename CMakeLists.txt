cmake_minimum_required(VERSION 3.19)
project(labirint)

set(CMAKE_CXX_STANDARD 14)

include_directories(labirint)

add_executable(labirint
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
