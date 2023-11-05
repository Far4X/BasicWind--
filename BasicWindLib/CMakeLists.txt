cmake_minimum_required(VERSION 3.0)

project(BasicWind++)

file(GLOB SOURCES "Classes/Objects/*.cpp" "Classes/Objects/Shapes/*.cpp" "Classes/Objects/Tools/Errors/*.cpp")
file(GLOB HEADERS "Classes/Objects/*.hpp" "Classes/Objects/Shapes/*.hpp" "Classes/Objects/Tools/Errors/*.hpp")

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_include_directories(BasicWind++ PUBLIC .Classes/Objects/)