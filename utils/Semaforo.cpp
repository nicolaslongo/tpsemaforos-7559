#include "Semaforo.h"

Semaforo :: Semaforo ( const std::string& nombre, const int cantidadDeSemaforos, 
			std::vector<int> valoresIniciales ) {
				
	this->valoresIniciales = valoresIniciales;
	this->cantidadDeSemaforos = cantidadDeSemaforos;
	key_t clave = ftok ( nombre.c_str(),'a' );
	this->id = semget ( clave,cantidadDeSemaforos,0666 | IPC_CREAT );
	
    for (int i = 0; i < cantidadDeSemaforos-1; i++) {
		this->inicializar(i, this->valoresIniciales.at(i));
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
	operacion.sem_op  = -1;	// restar 1 al semaforo
	operacion.sem_flg = SEM_UNDO;

	int resultado = semop ( this->id,&operacion,1 );
	return resultado;
}

int Semaforo :: v (int numeroSemaforo) const {

	struct sembuf operacion;

	operacion.sem_num = numeroSemaforo;	// numero de semaforo
	operacion.sem_op  = 1;	// sumar 1 al semaforo
	operacion.sem_flg = SEM_UNDO;

	int resultado = semop ( this->id,&operacion,1 );
	return resultado;
}

void Semaforo :: eliminar (int numeroSemaforo) const {
	semctl ( this->id,numeroSemaforo,IPC_RMID );
}
