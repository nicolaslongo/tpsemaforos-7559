#ifndef FABRICANTEDEMASA_H_
#define FABRICANTEDEMASA_H_

#include "Trabajador.h"

class FabricanteDeMasa : Trabajador {

    private:
        Logger* logger;
        int cantidadDePizzas;

    protected:

    public:
        FabricanteDeMasa(Logger* logger, int cantidad);
        ~FabricanteDeMasa();


};

#endif