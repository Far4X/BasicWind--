cmake_minimum_required(VERSION 3.0)

project(BasicWind++)

file(GLOB_RECURSE SOURCES "Classes/*.cpp")
file(GLOB_RECURSE HEADERS "Classes/*.hpp")

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_include_directories(BasicWind++ PUBLIC .Classes/Objects/)