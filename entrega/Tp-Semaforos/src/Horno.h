#ifndef HORNO_H_
#define HORNO_H_

#include "Trabajador.h"

class Horno : Trabajador {

    private:
        void hornear();
    protected:

    public:
        Horno(Logger* logger, int cantidad, Semaforo* semaforo);
        ~Horno();
        virtual int realizarMiTrabajo();

};
#endif