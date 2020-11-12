#include "../include/earth_utils.h"


int processCSV(std::ifstream& inFile, std::string kmlFileName)
{
    std::string strCountry, strCapital, strLat, strLong, strLine;
    int recordCount{};

    if(inFile)
    {
        getline(inFile, strLine);
        std::cout<< strLine << std::endl;
    }

    while(getline(inFile, strLine))
    {
        std::stringstream s_stream(strLine);
        //std::getline(s_stream, strCountry, ' ,');
        //std::getline(s_stream, strCapital, ' ,');
        //std::getline(s_stream, strLat, ' ,');
        //std::getline(s_stream, strLong, ' ,');
        std::cout<< strCountry << " ~ " << strCapital << " ~ " <<std::endl;
    }

    return recordCount;
}