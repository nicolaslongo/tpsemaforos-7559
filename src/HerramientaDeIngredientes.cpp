#include "HerramientaDeIngredientes.h"

HerramientaDeIngredientes::HerramientaDeIngredientes(Logger* logger, int cantidad, Semaforo* semaforo) :
    Trabajador (logger, cantidad, semaforo) {

    std::string msg = "HerramientaDeIngredientes: listo para trabajar.\n";
    this->logger->lockLogger();
    this->logger->writeToLogFile(msg);
    this->logger->unlockLogger();
}

int HerramientaDeIngredientes::realizarMiTrabajo() {

    int pid = fork();
    if (pid != 0) {
        return PARENT_PROCESS;
    }

    while( ! esHoraDeIrse() ) {

        // espero a que haya masa!
        sem->p(MASA_PREPARADA);
        // preparo y agrego los ingredientes
        sleep(1);
        this->cantidadDePizzasHechas++;
        std::cout << "Agregados los ingredientes a la pizza número " << 
                this->cantidadDePizzasHechas << endl;
        sem->v(INGREDIENTES_AGREGADOS);
    }

    sem->isDone(INGREDIENTES_AGREGADOS, 0);
    std::cout << "Semaforo INGREDIENTES_AGREGADOS es 0" << endl;

    return CHILD_PROCESS;
}


HerramientaDeIngredientes::~HerramientaDeIngredientes() {
}