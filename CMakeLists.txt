cmake_minimum_required(VERSION 3.13)

install(DIRECTORY 
    datastructure
    external
    geometry
    graph
    math
    monoid
    string
    util
    DESTINATION kyopro
    FILES_MATCHING PATTERN "*.hpp")