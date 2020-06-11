# include "Trabajador.h"

Trabajador::Trabajador(Logger* logger, int cantidad, Semaforo* semaforo) {
    this->logger = logger;
    this->cantidadDePizzas = cantidad;
    this->sem = semaforo;

}


bool Trabajador::esHoraDeIrse() {
    return (this->cantidadDePizzas == 0);
}

Trabajador::~Trabajador() {
}