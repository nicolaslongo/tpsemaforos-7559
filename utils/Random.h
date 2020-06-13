#ifndef RANDOM_H_
#define RANDOM_H_

#include <random>
#include <ctime>
#include <iostream>

class Random {

private:

public:
	Random ();
	~Random();

	static int getRandomNumber(unsigned int seed_number);
};

#endif
