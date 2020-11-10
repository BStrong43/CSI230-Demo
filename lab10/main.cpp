#include <iostream>
#include <vector>
#include "util.h"
#include "util.cpp"

using namespace std;

int main()
{
    //create vectors and populate values
    vector<string> words = vector<string>();
    words.push_back("cat");
    words.push_back("cat2");
    words.push_back("cat3");
    words.push_back("cat4");
    words.push_back("i am very tired");
    
    vector<double> numbers = vector<double>();
    numbers.push_back(394.4);
    numbers.push_back(10.7);
    numbers.push_back(419.9);
    numbers.push_back(68.9);
    numbers.push_back(5.2);

    cout << "Random string: " << randomElement(words) << endl;
    cout << "Sum of Nums: " << doSum(numbers) << endl;
    cout << "Avg of Nums: " << doAvg(numbers) << endl;
    cout << "Low of Nums: " << doLow(numbers) << endl;

    cout << "Calling camelCase with 'i just want this to work god please im so tired'" << endl;
    cout << camelCase("i just want this to work god please im so tired");

    return EXIT_SUCCESS;
}