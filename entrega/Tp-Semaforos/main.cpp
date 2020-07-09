#include "./utils/Logger.h"
#include "./src/FabricaDePizzas.h"

const std::string file = "/bin/bash";

int main(int argc, char *argv[]) {

    int CANT_PIZZAS = atoi(argv[argc-1]);
    Logger* logger = new Logger();
    std::vector<int> valoresIniciales {0, 0, 0, 5};
    Semaforo* sem = new Semaforo(file, (unsigned int) 'M', 4, valoresIniciales);

    FabricaDePizzas* fabrica = new FabricaDePizzas(logger, CANT_PIZZAS, sem);

    int res = fabrica->abrirLaFabrica();
    if (res == CHILD_PROCESS) {
        delete logger;
        delete fabrica;
        delete sem;
        return 0;
    }

    std::cout << "This is fine. Parent Process" << endl;
    delete logger;
    delete fabrica;
    delete sem;
    return 0;
}