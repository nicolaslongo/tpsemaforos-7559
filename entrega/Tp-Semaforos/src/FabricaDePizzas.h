#ifndef FABRICADEPIZZAS_H_
#define FABRICADEPIZZAS_H_

#include "../utils/Logger.h"
#include "FabricanteDeMasa.h"
#include "HerramientaDeIngredientes.h"
#include "RalladorDeQueso.h"
#include "Horno.h"

#include <sched.h>
using namespace std;


class FabricaDePizzas {

    private:
        Logger* logger;
        int cantidadDePizzas;
        Semaforo* sem;
        
        FabricanteDeMasa* fabricanteDeMasa;
        RalladorDeQueso* ralladorDeQueso;
        HerramientaDeIngredientes* herramientaDeIngredientes;
        Horno* horno;

    protected:

    public:
        FabricaDePizzas(Logger* logger, int cantidad, Semaforo* semaforo);
        ~FabricaDePizzas();
        int abrirLaFabrica();

};

#endif