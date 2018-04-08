#include<common/log.h>
#include<iomanip>
#include<string>
#include<sstream>
#ifdef _WIN32
#include <windows.h>
#endif

using armnet::Log;
using std::cout;
using std::endl;

Log armnetLog;

Log::Log()
{
    init();
}

Log::Log(int _logLevel)
{
    init(_logLevel);
}

Log::Log(std::string _outFileName)
{
    init(LOG_NONE, _outFileName);
}

Log::~Log()
{
    if (fileStream.is_open())
    {
        fileStream.close();
    }
}

void Log::init(int logLevel, std::string outFileName)
{
    minLogLevel = logLevel;
    fileFlag = false;

    if (outFileName != "")
    {
        if (fileStream.is_open())
        {
            fileStream.close();
        }

        fileStream.open(outFileName, std::ios::out);
        if (fileStream.is_open())
        {
            fileFlag = true;
        }
        else
        {
            //TODO: when can't open, do something
            cout << "error: can't open file " + outFileName << endl;
        }
    }
}

std::string Log::getTime(){
#ifdef _WIN32
    SYSTEMTIME sys;
    GetLocalTime(&sys);
    //TODO: how to control format
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << sys.wHour << ":"
       << std::setw(2) << std::setfill('0') << sys.wMinute << ":"
       << std::setw(2) << std::setfill('0') << sys.wSecond << ":"
       << std::setw(3) << std::setfill('0') << sys.wMilliseconds;
    return ss.str();
#endif
    //TODO： add linux get time
}

std::string Log::int2LogLevel(int level)
{
    std::string LogLevelName[LOG_NONE] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR",
        "FATAL"
    };

    if (level < 0 || level >= LOG_NONE)
    {
        return "";
    }
    else
    {
        return LogLevelName[level];
    }
}