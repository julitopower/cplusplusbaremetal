#include <iostream>
#include <string>
#include <tclap/CmdLine.h>

int main(int argc, char** argv) {
  std::cout << "Hi there" << std::endl;

  TCLAP::CmdLine cli("Testing command line argument parsing library", ' ', "1.0");
  TCLAP::ValueArg<int> times("t", "times", "Number of iterations", true, 10,"integer");
  cli.add(times);
  cli.parse(argc, argv);
  for(auto i = 0 ; i < times.getValue() ; ++i)
    std::cout << i << std::endl;
}
