#ifndef __ARMNET_COMMON_LOG_H__
#define __ARMNET_COMMON_LOG_H__

/*
 * ##日志工具##
 *
 * 设计该工具的目的为：
 * 1.LOG日志分级，当设置某一等级时，低于该等级的将不会输出。
 * 2.在LOG中输出 [时间戳][文件名][行号][等级][代号][类型][信息]。
 * 3.LOG的输出路径可控，目前支持输出到控制台、输出到文件。
 * 4.条件中止程序
 * 5.当不需要LOG信息时，可直接关闭，并且对代码的性能没有任何负面影响。
 * 6.在程序中，完全替代原始的cout输出的方式
 *
 *
 * ##using method:##
 *
 * armnetLog.init(WARNING, "log.txt");
 * LOGD << "Hello ARMNet" << std::endl;
 * LOGI << "Hello ARMNet" << std::endl;
 * LOGW << "Hello ARMNet" << std::endl;
 * LOGE << "Hello ARMNet" << std::endl;
 * LOGF << "Hello ARMNet" << std::endl;
 * LOG(DEBUG) << "Hello ARMNet" << std::endl;
 * LOG(INFO) << "Hello ARMNet" << std::endl;
 * LOG(WARNING) << "Hello ARMNet" << std::endl;
 * LOG(ERROR) << "Hello ARMNet" << std::endl;
 * LOG(FATAL) << "Hello ARMNet" << std::endl;
 * LOG(ERROR) << std::setw(8) << std::setfill('0') << 1231 << std::endl;
 * CHECK_NE(2, 3) << "2 != 3" << std::endl;
 */

#include<iostream>
#include<fstream>

//#define __NO_ARMNET_LOG__

#define LOGD _LOG(armnet::LOG_DEBUG)
#define LOGI _LOG(armnet::LOG_INFO)
#define LOGW _LOG(armnet::LOG_WARNING)
#define LOGE _LOG(armnet::LOG_ERROR)
#define LOGF _LOG(armnet::LOG_FATAL)

#define LOG(LOGLEVEL)  _LOG(armnet::LOG_##LOGLEVEL)

#define _LOG(LOGLEVEL) armnetLog << armnetLog.setLogtLevelBuffer(LOGLEVEL) << armnetLog.getTime()   \
                       << "  " << __FILE__ << ":"<< __LINE__ << "	"                              \
                       << armnetLog.int2LogLevel(LOGLEVEL) << "	  "

//TODO: 当define __NO_ARMNET_LOG__时，LOGF不会执行，会导致很严重的问题！！！！！！！！
#define CHECK_NE(value1, value2) if(value1 == value2) LOGF
#define CHECK_EQ(value1, value2) if(value1 != value2) LOGF
#define CHECK_LE(value1, value2) if(value1 > value2) LOGF
#define CHECK_GE(value1, value2) if(value1 < value2) LOGF
#define CHECK_LT(value1, value2) if(value1 >= value2) LOGF
#define CHECK_GT(value1, value2) if(value1 <= value2) LOGF

namespace armnet
{
    enum LogLevel
    {
        LOG_DEBUG,
        LOG_INFO,
        LOG_WARNING,
        LOG_ERROR,
        LOG_FATAL,
        LOG_NONE
    };

    class Log
    {
    public:
        Log();
        Log(int _logLevel);
        Log(std::string _outFileName);
        void init(int _logLevel = LOG_NONE, std::string _outFileName = "");

        ~Log();

        std::string getTime();
        std::string int2LogLevel(int level);

        inline std::string setLogtLevelBuffer(LogLevel level)
        {
#ifndef __NO_ARMNET_LOG__
            if (level < LOG_DEBUG || LOG_NONE < level)
            {
                logLevelBuffer = LOG_NONE;
                std::cout << "error: Log Level must within [" << LOG_DEBUG << ", "
                    << LOG_NONE << "]" << std::endl;
            }
            else
            {
                logLevelBuffer = level;
            }
#endif // !__NO_ARMNET_LOG__
            return "";
        }

        template<class T>
        inline Log& operator<<(T typeValue)
        {
#ifndef __NO_ARMNET_LOG__
            if (logLevelBuffer >= minLogLevel)
            {
                std::cout << typeValue;
                if (fileFlag == true)
                {
                    fileStream << typeValue;
                }
            }
#endif // !__NO_ARMNET_LOG__
            return *this;
        }

        inline Log& operator<<(std::ostream& (*function)(std::ostream&))
        {
#ifndef __NO_ARMNET_LOG__
            if (logLevelBuffer >= minLogLevel)
            {
                std::cout << function;
                if (fileFlag == true)
                {
                    fileStream << function;
                }
            }
#endif // !__NO_ARMNET_LOG__
            return *this;
        }

    private:
        bool fileFlag;               //if fileFlag = true, using fstream, or using iostream
                                     //TODO: add output direction
        int minLogLevel;
        std::fstream fileStream;

        //buffer
        int logLevelBuffer;         //log level of a log sentence
    };

}// namespace armnet


extern armnet::Log armnetLog;                        //global log value

#endif