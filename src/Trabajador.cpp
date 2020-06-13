# include "Trabajador.h"

Trabajador::Trabajador(Logger* logger, int cantidad, Semaforo* semaforo) {
    this->logger = logger;
    this->cantidadDePizzasPedidas = cantidad;
    this->cantidadDePizzasHechas = 0;
    this->sem = semaforo;

}


bool Trabajador::esHoraDeIrse() {
    return (
     (this->cantidadDePizzasPedidas - this->cantidadDePizzasHechas) == 0);
}

Trabajador::~Trabajador() {
}