#include <files.hpp>
#include <iostream>

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cout << "Must provide a file" << std::endl;
    return 0;
  }

  files::printFile(argv[1]);
  std::cout << files::countLines(argv[1]) << std::endl;
  std::cout << files::countWords(argv[1]) << std::endl;
  files::printUniqueWords(argv[1]);

}
