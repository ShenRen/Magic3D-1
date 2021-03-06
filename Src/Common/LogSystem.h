#pragma once
#include <fstream>
#include <iostream>

namespace MagicCore
{
    enum LogLevel
    {
        LOGLEVEL_DEBUG = 0,
        LOGLEVEL_INFO,
        LOGLEVEL_WARN,
        LOGLEVEL_ERROR,
        LOGLEVEL_OFF
    };

    extern const LogLevel gSystemLogLevel;

#define MagicLog(level) \
    if (level < MagicCore::gSystemLogLevel) ;\
    else MagicCore::LogSystem::Get()->GetOFStream() 
#define DebugLog MagicLog(MagicCore::LOGLEVEL_DEBUG)
#define InfoLog MagicLog(MagicCore::LOGLEVEL_INFO)
#define WarnLog MagicLog(MagicCore::LOGLEVEL_WARN)
#define ErrorLog MagicLog(MagicCore::LOGLEVEL_ERROR)

    class LogSystem
    {
    private:
        static LogSystem* mpLogSystem;
        LogSystem(void);
    public:
        static LogSystem* Get(void);
        ~LogSystem(void);
        std::ofstream& GetOFStream();
    public:
        std::ofstream mOFStream;
    };
}
