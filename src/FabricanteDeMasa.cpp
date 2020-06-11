#include "FabricanteDeMasa.h"

FabricanteDeMasa::FabricanteDeMasa (Logger* logger, int cantidad, Semaforo* semaforo) :
    Trabajador (logger, cantidad, semaforo) {

    std::cout << "FabricanteDeMasa: listo para trabajar" << endl;
    // logger->lockLogger();
    // logger->writeToLogFile("Soy el Fabricante de Masa, listo para trabajar");
    // logger->unlockLogger();
}

int FabricanteDeMasa::realizarMiTrabajo() {

    int pid = fork();
    if (pid != 0) {
        return PARENT_PROCESS;
    }

    while(this->cantidadDePizzas != 0) {

        // fabricarMasa
        sleep(3);
        std::cout << "Masa fabricada" << endl;
        this->cantidadDePizzas--;
        sem->v(MASA_PREPARADA);
    }

    return CHILD_PROCESS;
}


FabricanteDeMasa::~FabricanteDeMasa() {
    
}