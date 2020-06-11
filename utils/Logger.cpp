#include "Logger.h"

Logger::Logger() {

	this->nombre = nombre;
	this->fl.l_type = F_WRLCK;
	this->fl.l_whence = SEEK_SET;
	this->fl.l_start = 0;
	this->fl.l_len = 0;

    time_t now = time(0);
    std::string dt = string(ctime(&now));
    std::string name = string(FILE_FOLDER) + "log_file_" + dt + ".txt";

	this->fd = open (name.c_str(), O_CREAT|O_WRONLY, 0777);

}

int Logger::lockLogger() {
	this->fl.l_type = F_WRLCK;
	return fcntl ( this->fd,F_SETLKW,&(this->fl) );
}

int Logger::unlockLogger() {
	this->fl.l_type = F_UNLCK;
	return fcntl ( this->fd,F_SETLK,&(this->fl) );
}


ssize_t Logger::writeToLogFile(const char* buffer, const ssize_t buffsize) const {
	lseek(this->fd, 0, SEEK_END);
	return write(this->fd, buffer, buffsize);
}

ssize_t Logger::writeToLogFile(std::string string) {
	const char* msg = string.c_str();
	return writeToLogFile(msg, strlen(msg));
}


// que reciba un std::string y adentro de hace la magia de llamar a writeToLogFile común y chau
// ssize_t Logger::writeToLogFile(const char* buffer, const ssize_t buffsize) const {
// 	lseek(this->fd, 0, SEEK_END);
// 	return write(this->fd, buffer, buffsize);
// }

void Logger::closeFileInThisScope() {
	close(this->fd);
}


Logger::~Logger() {
	close(this->fd);
}
