#include "./utils/Logger.h"
#include "./src/FabricaDePizzas.h"

const std::string file = "/bin/bash";

int main() {

    int CANT_PIZZAS = 3;
    Logger* logger = new Logger();
    std::vector<int> valoresIniciales {0, 0};
    Semaforo* sem = new Semaforo(file, 2, valoresIniciales);

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