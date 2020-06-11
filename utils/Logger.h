#ifndef LOGGER_H_
#define LOGGER_H_

#define FILE_FOLDER "logfiles/"

#include <unistd.h>
#include <fcntl.h>
#include <string>
#include <string.h>
#include <ctime>
using namespace std;

class Logger {

    private:
      struct flock fl;
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
      void closeFileInThisScope();
};

#endif