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
        try {
            sem->p(MASA_PREPARADA);
        } catch(std::string& mensaje) {
            const char* msg = mensaje.c_str();
            this->logger->lockLogger();
            this->logger->writeToLogFile(msg, strlen(msg));
            this->logger->unlockLogger();
            exit(-1);
        }

        // preparo y agrego los ingredientes
        agregarIngredientes();
    }

    sem->isDone(INGREDIENTES_AGREGADOS, 0);
    std::cout << "Semaforo INGREDIENTES_AGREGADOS es 0" << endl;

    return CHILD_PROCESS;
}

void HerramientaDeIngredientes::agregarIngredientes() {
    
    int tiempo = tiempoDeTrabajo(this->cantidadDePizzasHechas);
    sleep(1);
    this->cantidadDePizzasHechas++;
    try {
        sem->v(INGREDIENTES_AGREGADOS);
    } catch(std::string& mensaje) {
        const char* msg = mensaje.c_str();
        this->logger->lockLogger();
        this->logger->writeToLogFile(msg, strlen(msg));
        this->logger->unlockLogger();
        exit(-1);
    }
    std::cout << "Agregados los ingredientes a la pizza número " << 
        this->cantidadDePizzasHechas << endl;

    std::string msg = "HerramientaDeIngredientes: agregar los ingredientes " +
        std::to_string(this->cantidadDePizzasHechas) 
        + " me tomó " + std::to_string(tiempo) + " segundos.\n";
    this->logger->lockLogger();
    this->logger->writeToLogFile(msg);
    this->logger->unlockLogger();
}

HerramientaDeIngredientes::~HerramientaDeIngredientes() {
}