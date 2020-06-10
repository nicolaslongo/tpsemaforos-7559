#ifndef TRABAJADOR_H_
#define TRABAJADOR_H_

#include "../utils/Logger.h"
#include <iostream>

// #include "Constantes.h"

class Trabajador {

    private:
        
    protected:
        Logger* logger;
        int cantidadDePizzas;

       
    public:

        Trabajador(Logger* logger, int cantidadDePizzas);
        virtual ~Trabajador();
        bool esHoraDeIrse();

};


#endif