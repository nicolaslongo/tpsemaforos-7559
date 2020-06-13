#include "Random.h"

Random::Random () {
				
}

int Random::getRandomNumber(unsigned int seed_number) {
    std::srand(seed_number * std::time(0));
    int desvio = 1 + (int) (5.0 * std::rand()/(RAND_MAX+1.0) );
    return desvio;
}


Random::~Random() {
}
