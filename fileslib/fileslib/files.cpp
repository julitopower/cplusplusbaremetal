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
    // Open file and make sure is a valid one
    std::ifstream is(filePath.c_str());
    if(!is.good())
      return 0;

    // Parse the file charater by character looking for
    // breakline, '\n'
    int linesCounter = 0;
    char c = is.get();
    while(is.good()) {
      linesCounter += (c == '\n') ? 1 : 0; 
      c = is.get();
    }

    is.close();

    // Return the number of times the '\n' character appears plus one
    return linesCounter + 1;
  }

  int countWords(std::string filePath) {
    // Open the file and make sure it is a valid one
    std::ifstream is(filePath.c_str());
    if(!is.good())
      return 0;

    // Initialize flags and counters
    int wordsCounter = 0;
    bool inWord = false;

    // Read the file one by one
    char c = is.get();
    while(is.good()) {
      if ((c == ' ' ||  c == '\t' || c =='\n')) {
	if(inWord) {
	  // Found a delimiter right after a non delimiter, increment counter
	  inWord = false;
	  ++wordsCounter;
	}
      } else {
	// Found a non delimiter
	inWord = true;
      }
      c = is.get();
    }

    // File finished while we were reading a word, increment counter
    if(inWord)
      wordsCounter++;

    is.close();
    return wordsCounter;
  }

  void printUniqueWords(std::string filePath){
    // Open file and make sure is valid
    std::ifstream is(filePath.c_str());
    if(!is.good())
      return;

    // Initialize the set
    std::set<std::string> words;

    // We use a stingstream to accumulate the characters of a running word
    std::stringstream ss;
    bool inWord = false;
    char c = is.get();
    while(is.good()) {
      if ((c == ' ' ||  c == '\t' || c =='\n')) {
	if (inWord) {
	  // End of word detected, add word to the Set
	  words.insert(ss.str());
	  ss.clear();
	  ss.str(std::string());
	  inWord = false;
	}
      } else {
	// Add character to current word
	ss << c;
	inWord = true;
      }
      c = is.get();
    }

    // We reached the end of a file whie reading a work, add it to the set
    if(inWord) {
      words.insert(ss.str());
    }

    is.close();

    // Finally print the contents of the set, traversing it using an iterator
    for(std::set<std::string>::iterator it = words.begin() ; it != words.end() ; ++it) {
      std::cout << *it << std::endl;
    }
  }

} 
