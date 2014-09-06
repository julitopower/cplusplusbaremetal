#include <files.hpp>
#include <iostream>
#include <fstream>
#include <set>
#include <sstream>

namespace files {

  void printFile(std::string filePath) {
    std::ifstream is(filePath.c_str());
    if(!is.good())
      return;

    char c = is.get();
    while(is.good()) {
      std::cout << c;
      c = is.get();
    }

    is.close();
  }

  int countLines(std::string filePath) {
    std::ifstream is(filePath.c_str());
    if(!is.good())
      return 0;

    int linesCounter = 0;
    char c = is.get();
    while(is.good()) {
      linesCounter += (c == '\n') ? 1 : 0; 
      c = is.get();
    }

    is.close();
    
    return linesCounter + 1;
    
  }

  int countWords(std::string filePath) {
    std::ifstream is(filePath.c_str());
    if(!is.good())
      return 0;

    int wordsCounter = 0;
    bool inWord = false;
    char c = is.get();
    while(is.good()) {
      if ((c == ' ' ||  c == '\t' || c =='\n')) {
	if(inWord) {
	  inWord = false;
	  ++wordsCounter;
	}
      } else {
	inWord = true;
      }
      c = is.get();
    }

    if(inWord)
      wordsCounter++;

    is.close();
    return wordsCounter;
  }

  void printUniqueWords(std::string filePath){
    std::ifstream is(filePath.c_str());
    if(!is.good())
      return;

    std::set<std::string> words;
    std::stringstream ss;
    bool inWord = false;
    char c = is.get();
    while(is.good()) {
      if ((c == ' ' ||  c == '\t' || c =='\n')) {
	if (inWord) {
	  words.insert(ss.str());
	  ss.clear();
	  ss.str(std::string());
	  inWord = false;
	}
      } else {
	ss << c;
	inWord = true;
      }
      c = is.get();
    }

    if(inWord) {
      words.insert(ss.str());
    }

    is.close();
    
    for(std::set<std::string>::iterator it = words.begin() ; it != words.end() ; ++it) {
      std::cout << *it << std::endl;
    }
  }

} 
