#include "FabricanteDeMasa.h"

FabricanteDeMasa::FabricanteDeMasa (Logger* logger, int cantidad, Semaforo* semaforo) :
    Trabajador (logger, cantidad, semaforo) {

    std::string msg = "FabricanteDeMasa: listo para trabajar.\n";
    this->logger->lockLogger();
    this->logger->writeToLogFile(msg);
    this->logger->unlockLogger();
}

int FabricanteDeMasa::realizarMiTrabajo() {

    int pid = fork();
    if (pid != 0) {
        return PARENT_PROCESS;
    }

    while( ! esHoraDeIrse() ) {

        // fabricarMasa
        sleep(1);
        this->cantidadDePizzasHechas++;
        std::cout << "Masa fabricada pizza número " << this->cantidadDePizzasHechas << endl;
        try {
            sem->v(MASA_PREPARADA);
        } catch(std::string& mensaje) {
            const char* msg = mensaje.c_str();
            this->logger->lockLogger();
            this->logger->writeToLogFile(msg, strlen(msg));
            this->logger->unlockLogger();
            exit(-1);
        }
    }

    sem->isDone(MASA_PREPARADA, 0);
    std::cout << "Semaforo MASA_PREPARADA es 0" << endl;

    return CHILD_PROCESS;
}


FabricanteDeMasa::~FabricanteDeMasa() {
    
}