#ifndef TRABAJADOR_H_
#define TRABAJADOR_H_

#include "../utils/Logger.h"
#include "../utils/Semaforo.h"
#include "Constantes.h"
#include <iostream>

// #include "Constantes.h"

class Trabajador {

    private:
        
    protected:
        Logger* logger;
        int cantidadDePizzasPedidas;
        int cantidadDePizzasHechas;
        Semaforo* sem;

       
    public:

        Trabajador(Logger* logger, int cantidadDePizzas, Semaforo* semaforo);
        virtual ~Trabajador();
        bool esHoraDeIrse();

        virtual int realizarMiTrabajo() = 0;

};


#endif