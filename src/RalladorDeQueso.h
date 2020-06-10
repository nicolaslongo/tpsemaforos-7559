#ifndef RALLADORDEQUESO_H_
#define RALLADORDEQUESO_H_

#include "Trabajador.h"

class RalladorDeQueso : Trabajador {

    private:
        Logger* logger;
        int cantidadDePizzas;

    protected:

    public:
        RalladorDeQueso(Logger* logger, int cantidad);
        ~RalladorDeQueso();


};
#endif