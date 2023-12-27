#include <iostream>

class Log{
  public:
    const int LogLevelError = 0;
    const int LogLevelWarning = 1;
    const int LogLevelInfo = 2;
  private:
    int m_LogLevel = LogLevelInfo;

  public:
    void SetLevel(int level){
      m_LogLevel = level;
    }

    void warn(const char* message){
        if (m_LogLevel >= LogLevelWarning)
          std::cout << "[Warning]: " << message << std::endl;
      }
    void info(const char* message){
      if (m_LogLevel >= LogLevelInfo)
        std::cout << "[Info]: " << message << std::endl;
    }
    void error(const char* message){
      if (m_LogLevel >= LogLevelError)
        std::cout << "[Error]: " << message << std::endl;
    }
};

int main(){
  Log log; // Instantiate the class
  log.SetLevel(log.LogLevelError);
  log.warn("Hello!");
  log.info("Hello!");
  log.error("Hello!");
  return 0;
}
