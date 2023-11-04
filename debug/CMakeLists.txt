cmake_minimum_required(VERSION 3.0)

project(BasicWind++)

file(GLOB SOURCES "Classes/Objects/*.cpp")
file(GLOB HEADERS "Classes/Objects/*.hpp")

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_include_directories(BasicWind++ PUBLIC .Classes/Objects/)