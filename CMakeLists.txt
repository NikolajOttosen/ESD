cmake_minimum_required(VERSION 2.8.7)
project(esdlab4 C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++0x")
#Set the sources of the project
set(project_sources
        main.cpp
        src/GPIO.cpp include/GPIO.h
        src/NumpadDriver.cpp include/NumpadDriver.h
        src/DisplayDriver.cpp include/DisplayDriver.h)

#Adds executable to the bin direcory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

#set(GPIO_INCLUDE_DIRS "/libs/")
#set(GPIO_LIBRARY      "/libs/GPIO/libGPIO.so")
#include_directories("${GPIO_INCLUDE_DIRS}")

add_executable(lab4 ${project_sources})
#target_link_libraries(embeddedProj "${GPIO_LIBRARY}")

#Tell cmake that x library is needed to compile
#target_link_libraries(embeddedProj PUBLIC x)