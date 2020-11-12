/**
 * @author Bilbo Baggins
 * @date 11/1/20
 * 
 */

#include "../include/logger.h"

bool log(std::string msg, std::string programName, std::ofstream& logFile)
{
    std::string strTime;

    time_t logTime = time(0);
    strTime = ctime(&logTime);

    int timeSize = strTime.size();
    if(timeSize)
    {
        strTime[timeSize -1] = ' ';
    }

    std::string strProgramName = programName;
    std::string strHostName;
    pid_t pid = getpid();

    if(logFile)
    {
        logFile << strTime << strHostName << " " << strProgramName << pid << ": " << msg << std::endl;
        return true;
    }
    else
    {
        return false;
    }
}