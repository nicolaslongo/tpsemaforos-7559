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
        try {
            sem->p(INGREDIENTES_AGREGADOS);
        } catch(std::string& mensaje) {
            const char* msg = mensaje.c_str();
            this->logger->lockLogger();
            this->logger->writeToLogFile(msg, strlen(msg));
            this->logger->unlockLogger();
            exit(-1);
        }
        // rallar el queso
        rallarQueso();

        try {
            sem->p(ESPACIOS_DISPONIBLES_EN_EL_HORNO);
        } catch(std::string& mensaje) {
            const char* msg = mensaje.c_str();
            this->logger->lockLogger();
            this->logger->writeToLogFile(msg, strlen(msg));
            this->logger->unlockLogger();
            exit(-1);
        }

        meterPizzaEnElHorno();

    }

    sem->isDone(PIZZAS_EN_EL_HORNO, 0);
    // std::cout << "Semaforo PIZZAS_EN_EL_HORNO es 0" << endl;

    return CHILD_PROCESS;
}

void RalladorDeQueso::rallarQueso() {

    int tiempo = tiempoDeTrabajo(this->cantidadDePizzasHechas);
    sleep(tiempo);
    this->cantidadDePizzasHechas++;
    std::cout << "Rallé el queso de la pizza número " << 
            this->cantidadDePizzasHechas << endl;

    std::string msg = "RalladorDeQueso: rallar el queso " +
        std::to_string(this->cantidadDePizzasHechas) 
        + " me tomó " + std::to_string(tiempo) + " segundos.\n";
    this->logger->lockLogger();
    this->logger->writeToLogFile(msg);
    this->logger->unlockLogger();

}

void RalladorDeQueso::meterPizzaEnElHorno() {

    try {
        sem->v(PIZZAS_EN_EL_HORNO);
    } catch(std::string& mensaje) {
        const char* msg = mensaje.c_str();
        this->logger->lockLogger();
        this->logger->writeToLogFile(msg, strlen(msg));
        this->logger->unlockLogger();
        exit(-1);
    }
    std::cout << "Metí la pizza número " << 
            this->cantidadDePizzasHechas << " en el horno" <<  endl;

}


RalladorDeQueso::~RalladorDeQueso() {
}