#include "FabricaDePizzas.h"

FabricaDePizzas::FabricaDePizzas(Logger* logger, int cantidad, Semaforo* semaforo) {

    this->logger = logger;
    this->cantidadDePizzas = cantidad;
    this->sem = semaforo;

    this->fabricanteDeMasa = new FabricanteDeMasa(logger, cantidadDePizzas, sem);
    this->herramientaDeIngredientes = new HerramientaDeIngredientes(logger,
            cantidadDePizzas, sem);
    this->ralladorDeQueso = new RalladorDeQueso(logger, cantidadDePizzas, sem);

    std::string msg = "Bienvenidos a ésta Fabrica de Pizzas!\n";
    this->logger->lockLogger();
    this->logger->writeToLogFile(msg);
    this->logger->unlockLogger();

}

int FabricaDePizzas::abrirLaFabrica() {

    int resultado;
    
    resultado = fabricanteDeMasa->realizarMiTrabajo();
    if (resultado == CHILD_PROCESS) {
        std::string msg = "Fabricante de masa huyendo.\n";
        this->logger->lockLogger();
        this->logger->writeToLogFile(msg);
        this->logger->unlockLogger();
        return resultado;
    }

    resultado = herramientaDeIngredientes->realizarMiTrabajo();
    if (resultado == CHILD_PROCESS) {
        std::string msg = "Herramienta de herramientas huyendo.\n";
        this->logger->lockLogger();
        this->logger->writeToLogFile(msg);
        this->logger->unlockLogger();
        return resultado;
    }

    resultado = ralladorDeQueso->realizarMiTrabajo();
    if (resultado == CHILD_PROCESS) {
        std::string msg = "Rallador de quesos huyendo.\n";
        this->logger->lockLogger();
        this->logger->writeToLogFile(msg);
        this->logger->unlockLogger();
        return resultado;
    }

    return PARENT_PROCESS;
}


FabricaDePizzas:: ~FabricaDePizzas() {

    delete fabricanteDeMasa;
    delete herramientaDeIngredientes;
    delete ralladorDeQueso;
}
