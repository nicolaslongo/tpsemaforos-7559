#include "RalladorDeQueso.h"

RalladorDeQueso::RalladorDeQueso(Logger* logger, int cantidad, Semaforo* semaforo) :
    Trabajador (logger, cantidad, semaforo) {

    std::cout << "RalladorDeQueso: listo para trabajar" << endl;

}

int RalladorDeQueso::realizarMiTrabajo() {

    int pid = fork();
    if (pid != 0) {
        return PARENT_PROCESS;
    }

    while(this->cantidadDePizzas != 0) {

        // espero a que haya masa!
        sem->p(INGREDIENTES_AGREGADOS);
        // rallar el queso
        sleep(1);
        std::cout << "Rallé el queso de la pizza" << endl;
        this->cantidadDePizzas--;
    }

    sem->eliminar(INGREDIENTES_AGREGADOS);

    return CHILD_PROCESS;
}


RalladorDeQueso::~RalladorDeQueso() {
}