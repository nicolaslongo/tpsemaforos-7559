#include "RalladorDeQueso.h"

RalladorDeQueso::RalladorDeQueso(Logger* logger, int cantidad) : Trabajador(
    logger, cantidad) {

    std::cout << "RalladorDeQueso: listo para trabajar" << endl;

}

RalladorDeQueso::~RalladorDeQueso() {
    
}