#ifndef FABRICANTEDEMASA_H_
#define FABRICANTEDEMASA_H_

#include "Trabajador.h"

class FabricanteDeMasa : Trabajador {

    private:
        void prepararMasa();
    protected:

    public:
        FabricanteDeMasa(Logger* logger, int cantidad, Semaforo* semaforo);
        ~FabricanteDeMasa();

        virtual int realizarMiTrabajo();


};

#endif