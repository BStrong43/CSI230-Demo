/**
 * @author Bilbo Baggins
 * @date 11/1/20
 *
 *   
 */
#ifndef LOGGER_H
#define LOGGER_H
#include <string>
#include <fstream>
#include <pwd.h>
#include <unistd.h>
#include <libgen.h>

bool log(std::string msg, std::string programName, std::ofstream& logFile);
#endif