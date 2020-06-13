#include "Logger.h"

Logger::Logger() {
	
	std::vector<int> valoresIniciales {1};
	valoresIniciales.push_back(1);
	std::cout << "Valor inicial es " << valoresIniciales.at(0) << endl;
	this->semaforo = new Semaforo(FILE_FOLDER, (unsigned int) 'L', 1, valoresIniciales);

    time_t now = time(0);
    std::string dt = string(ctime(&now));
    std::string name = string(FILE_FOLDER) + "log_file_" + dt + ".txt";

	this->fd = open (name.c_str(), O_CREAT|O_WRONLY, 0777);

}

int Logger::lockLogger() {
	int resultado;
	try {
		resultado = this->semaforo->p(this->numeroSemaforo);
	} catch(std::string& mensaje){
		std::cout << "Error lockeando logger : " << mensaje << endl;
		resultado = -1;
	}
	return resultado;
}

int Logger::unlockLogger() {
	int resultado;
	try {
		resultado = this->semaforo->v(this->numeroSemaforo);
	} catch(std::string& mensaje){
		std::cout << "Error lockeando logger : " << mensaje << endl;
		resultado = -1;
	}
	return resultado;
}


ssize_t Logger::writeToLogFile(const char* buffer, const ssize_t buffsize) const {
	lseek(this->fd, 0, SEEK_END);
	return write(this->fd, buffer, buffsize);
}

ssize_t Logger::writeToLogFile(std::string string) {
	const char* msg = string.c_str();
	return writeToLogFile(msg, strlen(msg));
}

void Logger::cerrarSemaforo() {
	semaforo->eliminar(this->numeroSemaforo);
}

Logger::~Logger() {
	close(this->fd);
	delete semaforo;
}
