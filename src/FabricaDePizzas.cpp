#include "FabricaDePizzas.h"

FabricaDePizzas::FabricaDePizzas(Logger* logger, int cantidad, Semaforo* semaforo) {

    this->logger = logger;
    std::string msg = "Bienvenidos a ésta Fabrica de Pizzas!\n";
    this->logger->lockLogger();
    this->logger->writeToLogFile(msg);
    this->logger->unlockLogger();

    std::cout << "Hoy fabricaremos " << cantidad << " pizzas." << endl;

    this->cantidadDePizzas = cantidad;
    this->sem = semaforo;

    this->fabricanteDeMasa = new FabricanteDeMasa(logger, cantidadDePizzas, sem);
    this->herramientaDeIngredientes = new HerramientaDeIngredientes(logger,
            cantidadDePizzas, sem);
    this->ralladorDeQueso = new RalladorDeQueso(logger, cantidadDePizzas, sem);
    this->horno = new Horno(logger, cantidadDePizzas, sem);

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
        std::string msg = "Herramienta de ingredientes huyendo.\n";
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

    resultado = horno->realizarMiTrabajo();
    if (resultado == CHILD_PROCESS) {
        std::string msg = "Horno cerrando.\nThis is it fellas!\n";
        this->logger->lockLogger();
        this->logger->writeToLogFile(msg);
        this->logger->unlockLogger();
        // cierro el semaforo del Logger, no queda nada por hacer!

        this->logger->cerrarSemaforo();
        return resultado;
    }

    return PARENT_PROCESS;
}


FabricaDePizzas:: ~FabricaDePizzas() {

    delete fabricanteDeMasa;
    delete herramientaDeIngredientes;
    delete ralladorDeQueso;
    delete horno;
}