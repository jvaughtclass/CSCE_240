// copyright 2023 jvaught
// Description: This program will read a file and output the most frequent
// characters, least frequent characters, frequency table, and bar chart.
#include <cctype>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>

#include "program3functions.h"

using namespace std;

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cerr << "Usage: " << argv[0] << " <input_file>" << endl;
    return 1;
  }

  ifstream inputFile(argv[1]);

  if (!inputFile) {
    cerr << "Error: could not open input file: " << argv[1] << endl;
    return 1;
  }

  int freq[26] = {0};
  char c;

  while (inputFile.get(c)) {
    if (isAlphabetic(c)) {
      updateFrequency(c, freq);
    }
  }

  printMostFrequent(freq);
  printLeastFrequent(freq);
  cout << endl;
  printFrequencyList(freq);  // works
  cout << endl;
  printBarChart(freq);

  return 0;
}
