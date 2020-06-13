#include "Horno.h"

Horno::Horno(Logger* logger, int cantidad, Semaforo* semaforo) :
    Trabajador (logger, cantidad, semaforo) {

    std::string msg = "Horno: listo para trabajar.\n";
    this->logger->lockLogger();
    this->logger->writeToLogFile(msg);
    this->logger->unlockLogger();
}

int Horno::realizarMiTrabajo() {

    int pid = fork();
    if (pid != 0) {
        return PARENT_PROCESS;
    }

    while( ! esHoraDeIrse() ) {

        // espero a que haya pizzas en el horno!
        sem->p(PIZZAS_EN_EL_HORNO);
        // Horneo la pizza!!!
        sleep(4);
        this->cantidadDePizzasHechas++;
        std::cout << "Horneé la pizza número " << this->cantidadDePizzasHechas 
                <<  " y hay un espacio más!" << endl;
        sem->v(ESPACIOS_DISPONIBLES_EN_EL_HORNO);
        
    }

    std::string msg = "Horno: hoy, con esto, yo termino el trabajo!\n";
    this->logger->lockLogger();
    this->logger->writeToLogFile(msg);
    this->logger->unlockLogger();
    
    sem->eliminar(MASA_PREPARADA);
    sem->eliminar(INGREDIENTES_AGREGADOS);
    sem->eliminar(ESPACIOS_DISPONIBLES_EN_EL_HORNO);
    sem->eliminar(PIZZAS_EN_EL_HORNO);

    return CHILD_PROCESS;
}


Horno::~Horno() {
}