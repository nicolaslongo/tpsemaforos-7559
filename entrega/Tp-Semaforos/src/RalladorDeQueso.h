#ifndef RALLADORDEQUESO_H_
#define RALLADORDEQUESO_H_

#include "Trabajador.h"

class RalladorDeQueso : Trabajador {

    private:
        void rallarQueso();
        void meterPizzaEnElHorno();

    protected:

    public:
        RalladorDeQueso(Logger* logger, int cantidad, Semaforo* semaforo);
        ~RalladorDeQueso();
        virtual int realizarMiTrabajo();

};
#endif