#include "HerramientaDeIngredientes.h"

HerramientaDeIngredientes::HerramientaDeIngredientes(Logger* logger, int cantidad, Semaforo* semaforo) :
    Trabajador (logger, cantidad, semaforo) {

    std::cout << "HerramientaDeIngredientes: listo para trabajar" << endl;

}

int HerramientaDeIngredientes::realizarMiTrabajo() {

    int pid = fork();
    if (pid != 0) {
        return PARENT_PROCESS;
    }

    while(this->cantidadDePizzas != 0) {

        // espero a que haya masa!
        sem->p(MASA_PREPARADA);
        // preparo y agrego los ingredientes
        sleep(1);
        std::cout << "Agregados los ingredientes a la pizza" << endl;
        sem->v(INGREDIENTES_AGREGADOS);
        this->cantidadDePizzas--;
    }

    sem->eliminar(MASA_PREPARADA);

    return CHILD_PROCESS;
}


HerramientaDeIngredientes::~HerramientaDeIngredientes() {
}