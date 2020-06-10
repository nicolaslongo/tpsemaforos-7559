#include "FabricanteDeMasa.h"

FabricanteDeMasa::FabricanteDeMasa (Logger* logger, int cantidad) : Trabajador 
    (logger, cantidad) {

    std::cout << "FabricanteDeMasa: listo para trabajar" << endl;
    // logger->lockLogger();
    // logger->writeToLogFile("Soy el Fabricante de Masa, listo para trabajar");
    // logger->unlockLogger();
}

FabricanteDeMasa::~FabricanteDeMasa() {
    
}