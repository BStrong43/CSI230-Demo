#include <iostream>
#include "../include/logger.h"
#include "../include/earth_utils.h"
#include <unistd.h>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
    /*
    passwd *pws;
    pws = getpwuid(geteuid());
    cout << "user is:" << pws->pw_name << " userid is: " << pws->pw_uid << endl;
    
    pid_t pid = getpid();
    string programName = basename(argv[0]);

    cout << "the PID of: " << programName << " is " << pid << endl;
    */

    int opt{};
    bool kmlFlag{false};
    bool logFlag{false};
    string kmlValue;
    string logValue;
    bool optErr = true;

    while((opt = getopt(argc, argv, "k:l:")) != EOF)
    {
        switch(opt)
        {
            case 'k':
                kmlFlag = true;
                kmlValue = optarg;
                break;
            
            case 'l':
                logFlag = true;
                logValue = optarg;
                break;

            default:
                optErr = true;
                break;

        }
    }

    

    if(kmlFlag && logFlag)
    {
        cout<< "Flags set" << endl;
        if(logValue.empty() || kmlValue.empty())
        {
            optErr = true;
            cout << "Option arguments not set" << endl;
        }
        else
        {
            ofstream flog;
            flog.open(logValue, ios_base::app);
            if(flog)
            {
                std::string programName = basename(argv[0]);
                std::string msg = "The kmlFile is:" + kmlValue + " and the logFile is:" + logValue;
                log(msg, programName, flog);
                optErr = false;
                flog.close();

                ifstream inFile;
                inFile.open(kmlValue);
                if(inFile)
                {
                    int recordCount = processCSV(inFile, kmlValue + ".kml");
                    inFile.close();
                    if(recordCount)
                    {
                        cout<<recordCount << " records processed" << endl;
                        optErr = false;
                    }
                }
                else
                {
                    cout<<"couldn't open file: " << kmlValue <<endl;
                    optErr = true;
                }

            }
            else
            {
                cout << "couldn't open " << logValue << endl;
                optErr = true;
            }
            
        }
    }
    else
    {
        cout<< "error - flags are not set" << endl;
        optErr = true;
    }

    if(optErr)
    {
        return EXIT_FAILURE;
    }

    

    //cout << "flags - kmlFlag:" << kmlFlag << " logFlag: " << logFlag << endl;
    //cout << "The kmlValue is : " << kmlValue << " and logfile is: " << logValue << endl;
    
    return EXIT_SUCCESS;
}