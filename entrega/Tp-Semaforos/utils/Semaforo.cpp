#include "Semaforo.h"

Semaforo :: Semaforo ( const std::string& nombre, unsigned int initializer,
			const int cantidadDeSemaforos, std::vector<int> valores ) {
				
	this->valoresIniciales = valores;
	this->cantidadDeSemaforos = cantidadDeSemaforos;
	key_t key = ftok ( nombre.c_str(),initializer );
	this->id = semget ( key,cantidadDeSemaforos,0666 | IPC_CREAT );
	
    for (int i = 0; i < cantidadDeSemaforos; i++) {

		int valor = this->valoresIniciales.at(i);
		std::cout << "Inicializando semaforo " << i << " del archivo " 
			<< std::to_string(initializer) << " en valor " << valor << std::endl;
		this->inicializar(i, valor);

	}
}

Semaforo::~Semaforo() {
}

int Semaforo :: inicializar (int semaforoNumero, int valor) const {

	union semnum {
		int val;
		struct semid_ds* buf;
		ushort* array;
	};

	semnum init;
	init.val = valor;
	int resultado = semctl ( this->id,semaforoNumero,SETVAL,init );
	return resultado;
}

int Semaforo :: p (int numeroSemaforo) const {

	struct sembuf operacion;

	operacion.sem_num = numeroSemaforo;	// numero de semaforo
	operacion.sem_op  = -1;				// restar 1 al semaforo
	operacion.sem_flg = SEM_UNDO;

	int resultado = semop ( this->id,&operacion,1 );
	if (resultado == -1) {
		throw "Error ejecutando wait() sobre el semaforo " + std::to_string(numeroSemaforo);
	}
	return resultado;
}

int Semaforo :: v (int numeroSemaforo) const {

	struct sembuf operacion;

	operacion.sem_num = numeroSemaforo;	// numero de semaforo
	operacion.sem_op  = 1;				// sumar 1 al semaforo
	operacion.sem_flg = SEM_UNDO;

	int resultado = semop ( this->id,&operacion,1 );
	if (resultado == -1) {
		throw "Error ejecutando signal() sobre el semaforo " + std::to_string(numeroSemaforo);
	}
	return resultado;
}

int Semaforo :: isDone (int numeroSemaforo, int valorEsperado) const {

	struct sembuf operacion;

	operacion.sem_num = numeroSemaforo;	// numero de semaforo
	operacion.sem_op  = valorEsperado;	// espera a que el semaforo sea del valor esperado
	operacion.sem_flg = SEM_UNDO;

	int resultado = semop ( this->id,&operacion,1 );
	if (resultado == -1) {
		throw "Error esperando a que valga 0 el semaforo " + std::to_string(numeroSemaforo);
	}
	return resultado;
}


void Semaforo :: eliminar (int numeroSemaforo) const {
	semctl ( this->id,numeroSemaforo,IPC_RMID );
}
