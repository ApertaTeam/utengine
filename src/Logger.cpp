#include "Logger.h"

#include <ctime>

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
    Logger::Logger()
    {

    }

    Logger::Logger(std::string logfile)
    {
        // TODO: Open a log file for appending to
    }

    Logger::~Logger()
    {
        // TODO: Close said log file
    }

    void Logger::_unique_Log(LogLevel level, std::string message, const char* calling, const char* file, int line)
    {
        std::time_t t = std::time(0);
        std::tm* now = std::localtime(&t);
        // "2019-7-7@15:55 [INFO | main] This is a test log"
        std::cout << now->tm_year + 1900 << '-'
            << (now->tm_mon + 1) << '-'
            << now->tm_mday
            << "@"
            << now->tm_hour << ":"
            << now->tm_min
            << " [" << LevelToString(level) << " | " << calling << "@" << file << ":" << line << "] "
            << message << std::endl;
    }
}