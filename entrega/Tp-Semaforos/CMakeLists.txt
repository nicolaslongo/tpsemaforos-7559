cmake_minimum_required(VERSION 2.8)
project(tpSemaforos)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -g")
add_executable(tpSemaforos main.cpp
utils/Logger.cpp
utils/Semaforo.cpp
utils/Random.cpp
src/Trabajador.cpp
src/FabricaDePizzas.cpp
src/FabricanteDeMasa.cpp
src/HerramientaDeIngredientes.cpp
src/RalladorDeQueso.cpp
src/Horno.cpp)
