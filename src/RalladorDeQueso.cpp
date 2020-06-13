#include "RalladorDeQueso.h"

RalladorDeQueso::RalladorDeQueso(Logger* logger, int cantidad, Semaforo* semaforo) :
    Trabajador (logger, cantidad, semaforo) {

    std::string msg = "RalladorDeQueso: listo para trabajar.\n";
    this->logger->lockLogger();
    this->logger->writeToLogFile(msg);
    this->logger->unlockLogger();
}

int RalladorDeQueso::realizarMiTrabajo() {

    int pid = fork();
    if (pid != 0) {
        return PARENT_PROCESS;
    }

    while( ! esHoraDeIrse() ) {

        // espero a que estén los ingredientes listos!
        int resultado = sem->p(INGREDIENTES_AGREGADOS);
        if (resultado != 0) {
            std::cout << "dio distinto de cero" << endl;
        }
        // rallar el queso
        sleep(1);
        this->cantidadDePizzasHechas++;
        std::cout << "Rallé el queso de la pizza número " << 
                this->cantidadDePizzasHechas << endl;
        // si hay espacio en el horno, rallo el queso
        resultado = sem->p(ESPACIOS_DISPONIBLES_EN_EL_HORNO);
        if (resultado != 0) {
            std::cout << "dio distinto de cero" << endl;
        }
        resultado = sem->v(PIZZAS_EN_EL_HORNO);
        if (resultado != 0) {
            std::cout << "dio distinto de cero" << endl;
        }
    }
    sem->isDone(PIZZAS_EN_EL_HORNO, 0);
    std::cout << "Semaforo PIZZAS_EN_EL_HORNO es 0" << endl;


    return CHILD_PROCESS;
}


RalladorDeQueso::~RalladorDeQueso() {
}