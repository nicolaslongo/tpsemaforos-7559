# include "Trabajador.h"

Trabajador::Trabajador(Logger* logger, int cantidad) {
    this->logger = logger;
    this->cantidadDePizzas = cantidad;

}


bool Trabajador::esHoraDeIrse() {
    return (this->cantidadDePizzas == 0);
}

Trabajador::~Trabajador() {
}