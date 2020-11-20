#include <iostream>
#include <boost/program_options.hpp>
#include <boost/algorithm/algorithm.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/hex.hpp>

//boost namespaces
using namespace boost::program_options;
using namespace boost::algorithm;

void tolowerCase(std::string words)
{//from boost algorithms
    to_lower(words);
    std::cout << words << std::endl;
}

void toupperCase(std::string words)
{//from boost algorithms
    to_upper(words);
    std::cout << words << std::endl;
}

void to_hex(int dec)
{//from boost algorithms
    to_hex(dec); 
    std::cout << dec << std::endl;
}

int main(int argc, const char *argv[])
{
    try
  {
    options_description desc{"Options"};
    //add options/notifiers
    desc.add_options()
      ("help,h", "Help screen")
      ("sml", value<std::string>()->notifier(tolowerCase), "Lower Case")
      ("lrg", value<std::string>()->notifier(toupperCase), "Upper Case")
      ("hex", value<int>()->notifier(to_hex), "Age");

    variables_map vm;
    store(parse_command_line(argc, argv, desc), vm);
    notify(vm);
  }
  catch (const error &ex)
  {
    std::cerr << ex.what() << '\n';
  }
    //std::cout<<"Hello World"<<std::endl;

    if(argc = 0)
        std::cout<< "please pass options and parameters" << std::endl;

    return EXIT_SUCCESS;
}