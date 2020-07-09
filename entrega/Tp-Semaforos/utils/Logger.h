#ifndef LOGGER_H_
#define LOGGER_H_

#define FILE_FOLDER "logfiles/"

#include "Semaforo.h"

#include <vector>
#include <fcntl.h>
#include <unistd.h>
#include <string>
#include <string.h>
#include <ctime>
using namespace std;

class Logger {

    private:
      Semaforo* semaforo;
      int numeroSemaforo = 0;
      int fd;
      std::string nombre;

    protected:

    public:
      Logger();
      ~Logger();
      int lockLogger();
      int unlockLogger();
      ssize_t writeToLogFile(const char* buffer, const ssize_t buffsize) const;
      ssize_t writeToLogFile(std::string string);
      void cerrarSemaforo();
};

#endif