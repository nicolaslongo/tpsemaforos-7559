cmake_minimum_required(VERSION 2.8)
project(tpSemaforos)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -g")
add_executable(tpSemaforos main.cpp
utils/Logger.cpp
src/Trabajador.cpp
src/FabricanteDeMasa.cpp
src/RalladorDeQueso.cpp)