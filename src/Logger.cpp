#include "Logger.h"
#include "Common.h"

#include <ctime>
#include <sstream>

const char* LevelToString(UT::Logger::LogLevel level)
{
    switch (level)
    {
    case UT::Logger::Info:
        return "INFO";
    case UT::Logger::Error:
        return "ERROR";
    case UT::Logger::Warning:
        return "WARN";
    // case UT::Logger::Debug:
    default:
        return "DEBUG";
    }
}

namespace UT
{
    static Logger globalLogger{};
    
    Logger::Logger()
        : logFile(GetExecutableDirectory() + "/engine.log", std::ios::app)
    {
    }

    Logger::Logger(std::string logfile)
        : logFile(GetExecutableDirectory() + "/" + logfile, std::ios::app)
    {
    }

    Logger::~Logger()
    {
    }

    Logger* Logger::GetGlobalLogger()
    {
        return &globalLogger;
    }

    void Logger::_unique_Log(LogLevel level, std::string message, const char* calling, const char* file, int line)
    {
        std::time_t t = std::time(0);
        std::tm* now = std::localtime(&t);
        std::stringstream out;
        // "2019-7-7@15:55 [INFO | main] This is a test log"
        out << now->tm_year + 1900 << '-'
            << (now->tm_mon + 1) << '-'
            << now->tm_mday
            << "@"
            << now->tm_hour << ":"
            << now->tm_min
            << " [" << LevelToString(level) << " | " << calling << "@" << file << ":" << line << "] "
            << message << "\n";
        std::cout << out.str();
        logFile << out.str();
    }
}