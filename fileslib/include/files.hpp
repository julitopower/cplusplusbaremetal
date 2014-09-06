#ifndef FILES
#define FILES
#include <string>

namespace files {

  void printFile(std::string filePath);

  int countLines(std::string filePath);

  int countWords(std::string filePath);

  void printUniqueWords(std::string filePath);
};

#endif
