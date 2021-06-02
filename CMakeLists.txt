cmake_minimum_required(VERSION 3.19)
project(Labirint_git)

set(CMAKE_CXX_STANDARD 14)

include_directories(labirint E:/OneDrive/Visual studio workspace/Libs/SFML-2.5.1/include)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Labirint_git ${SFML_LIBRARIES})
endif ()
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

