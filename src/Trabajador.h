#ifndef TRABAJADOR_H_
#define TRABAJADOR_H_

#include "../utils/Logger.h"
#include "../utils/Semaforo.h"
#include "../utils/Random.h"
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

        bool esHoraDeIrse();
        int tiempoDeTrabajo(unsigned int seed_number);

        virtual int realizarMiTrabajo() = 0;
       
    public:

        Trabajador(Logger* logger, int cantidadDePizzas, Semaforo* semaforo);
        virtual ~Trabajador();


};


#endif