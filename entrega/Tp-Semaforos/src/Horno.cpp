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

        // espero a que haya pizzas en el horno
        try {
            sem->p(PIZZAS_EN_EL_HORNO);
        } catch(std::string& mensaje) {
            const char* msg = mensaje.c_str();
            this->logger->lockLogger();
            this->logger->writeToLogFile(msg, strlen(msg));
            this->logger->unlockLogger();
            exit(-1);
        }

        hornear();
        
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

void Horno::hornear() {

    int tiempo = TIEMPO_MINIMO_DE_HORNO + tiempoDeTrabajo(this->cantidadDePizzasHechas);
    sleep(tiempo);
    this->cantidadDePizzasHechas++;
    try {
        sem->v(ESPACIOS_DISPONIBLES_EN_EL_HORNO);
    } catch(std::string& mensaje) {
        const char* msg = mensaje.c_str();
        this->logger->lockLogger();
        this->logger->writeToLogFile(msg, strlen(msg));
        this->logger->unlockLogger();
        exit(-1);
    }
    std::cout << "Horneé la pizza número " << this->cantidadDePizzasHechas 
            <<  " y hay un espacio más!" << endl;

    std::string msg = "Horno: hornear la pizza " +
        std::to_string(this->cantidadDePizzasHechas) 
        + " me tomó " + std::to_string(tiempo) + " segundos.\n";
    this->logger->lockLogger();
    this->logger->writeToLogFile(msg);
    this->logger->unlockLogger();

}


Horno::~Horno() {
}