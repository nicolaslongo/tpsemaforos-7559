#ifndef SEMAFORO_H_
#define SEMAFORO_H_

#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <string>
#include <vector>

class Semaforo {

private:
	int id;
	std::vector<int> valoresIniciales;
	int cantidadDeSemaforos;
	
	int inicializar (int semaforoNumero, int valor) const;

public:
	Semaforo ( const std::string& nombre,const int cantidadDeSemaforos,
					std::vector<int> valorInicial );
	~Semaforo();

	int p (int numeroSemaforo) const; // decrementa
	int v (int numeroSemaforo) const; // incrementa
	void eliminar (int numeroSemaforo) const;
};

#endif /* SEMAFORO_H_ */
