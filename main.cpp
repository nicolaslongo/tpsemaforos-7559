#include "./utils/Logger.h"
#include "./src/FabricanteDeMasa.h"
#include "./src/HerramientaDeIngredientes.h"
#include "./src/RalladorDeQueso.h"

int main() {

    int CANT_PIZZAS = 25;
    Logger* logger = new Logger();

    FabricanteDeMasa* fabricanteDeMasa = new FabricanteDeMasa(logger, CANT_PIZZAS);
    // HerramientaDeIngredientes* herramientaDeIngredientes = new HerramientaDeIngredientes(logger);
    RalladorDeQueso* ralladorDeQueso = new RalladorDeQueso(logger, CANT_PIZZAS);
    
    std::cout << "This is fine" << endl;

    delete logger;
    delete fabricanteDeMasa;
    delete ralladorDeQueso;
    return 0;
}