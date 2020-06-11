#ifndef HERRAMIENTADEINGREDIENTES_H_
#define HERRAMIENTADEINGREDIENTES_H_

#include "Trabajador.h"

class HerramientaDeIngredientes : Trabajador {

    private:

    protected:

    public:
        HerramientaDeIngredientes(Logger* logger, int cantidad, Semaforo* semaforo);
        ~HerramientaDeIngredientes();
        virtual int realizarMiTrabajo();

};
#endif