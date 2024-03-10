cmake_minimum_required(VERSION 3.16)
project(Video_Wall)


option(BUILD_TV_WALL "" ON)


if (BUILD_TV_WALL)
    add_subdirectory(Video_Wall)
endif ()

