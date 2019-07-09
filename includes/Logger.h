#ifndef UT_LOGGER_H
#define UT_LOGGER_H

#include <string>
#include <fstream>
#include <iostream>

namespace UT
{
    class Logger
    {
    public:
        Logger();
        Logger(std::string logfile);
        ~Logger();

        enum LogLevel
        {
            Error,
            Info,
            Debug,
            Warning
        };
        void _unique_Log(LogLevel level, std::string message, const char* calling, const char* file, int line);
        static Logger* GetGlobalLogger();
    private:
        Logger(Logger&);
        void operator= (Logger&);

        std::ofstream logFile;
    };
}

#define GlobalLogger UT::Logger::GetGlobalLogger()

#if defined(WIN32) || defined(_WIN32)
    #define Log(level, message) \
        _unique_Log(level, message, __FUNCTION__, __FILE__, __LINE__)
#else
    #define Log(level, message) \
        _unique_Log(level, message, __func__, __FILE__, __LINE__)
#endif

#endif