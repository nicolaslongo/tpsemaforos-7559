# include "Trabajador.h"

Trabajador::Trabajador(Logger* logger, int cantidad, Semaforo* semaforo) {
    this->logger = logger;
    this->cantidadDePizzasPedidas = cantidad;
    this->cantidadDePizzasHechas = 0;
    this->sem = semaforo;

}

int Trabajador::tiempoDeTrabajo(unsigned int seed_number) {
    return Random::getRandomNumber(seed_number);
}

bool Trabajador::esHoraDeIrse() {
    return (
     (this->cantidadDePizzasPedidas - this->cantidadDePizzasHechas) == 0);
}

Trabajador::~Trabajador() {
}