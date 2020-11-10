#include "util.h"

std::string randomElement(std::vector<std::string> list)
{
    int randomIndex = rand() % list.size();
    return list[randomIndex];
}

double randomElement (std::vector<double> list)
{
    int randomIndex = rand() % list.size(); //just how i was taught to get a random element
    return list[randomIndex];
}

std::string camelCase(std::string notACamel)
{
    int wordLength = notACamel.length();
    int camelLength = 0;

    for(int i=0; i < wordLength; i++) //iterate through word
    {
        if(notACamel[i] == ' ') //char is space | copy letter 1 space ahead and capitalize
            notACamel[i+1] = toupper(notACamel[i+1]);
        else                    //char is not space | move string down + increase cap
            notACamel[camelLength++] = notACamel[i];       
    }

    return notACamel.substr(0, camelLength);
}

double doSum(std::vector<double> list)
{
    double sum = 0;
    for(int i = 0; i< list.size(); i++)
    {
        sum += list[i]; //iterate and add
    }
    return sum;
}

double doAvg(std::vector<double> list)
{
    double sum = doSum(list); //Just reuse sum
    return (sum / list.size());//Divide and conquer!
}

double doLow(std::vector<double> list)
{
    double low = 0;

    for(int i=0; i< list.size(); i++)
    {//loop through and check value is still lowest
        low = std::min(low, list[i]);
    }

    return low;
}