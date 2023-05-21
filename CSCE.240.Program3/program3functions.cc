// Copyright 2023 jvaught
// Description: This program will read a file and output the most frequent
// characters, least frequent characters, frequency table, and bar chart.

#include "program3functions.h"

#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;

const int NUM_CHARS = 26;

// converts a character to lowercase
bool isAlphabetic(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

char toLowerCase(char c) {
  if (c >= 'A' && c <= 'Z') {
    return c + ('a' - 'A');
  }
  return c;
}

void updateFrequency(char c, int *freq) { freq[toLowerCase(c) - 'a']++; }

void printMostFrequent(int *freq) {
  int maxFreq = 0;
  for (int i = 0; i < 26; i++) {
    if (freq[i] > maxFreq) {
      maxFreq = freq[i];
    }
  }

  cout << "Highest frequency character";
  if (maxFreq > 1) {
    cout << "s";
  }
  cout << " (appeared " << maxFreq << " time";
  if (maxFreq > 1) {
    cout << "s";
  }
  cout << " in the file): ";

  bool firstChar = true;
  for (int i = 0; i < 26; i++) {
    if (freq[i] == maxFreq) {
      if (!firstChar) {
        cout << ", ";
      }
      cout << (char)('a' + i);
      firstChar = false;
    }
  }
  cout << endl;
}

void printLeastFrequent(int *freq) {
  int minFreq = -1;
  for (int i = 0; i < 26; i++) {
    if (freq[i] >= 0 && (minFreq == -1 || freq[i] < minFreq)) {
      minFreq = freq[i];
    }
  }

  cout << "Lowest frequency character";
  if (minFreq > 1) {
    cout << "s";
  }
  cout << " (appeared " << minFreq << " time";
  if (minFreq > 1) {
    cout << "s";
  }
  cout << " in the file): ";

  int numChars = 0;
  for (int i = 0; i < 26; i++) {
    if (freq[i] == minFreq) {
      numChars++;
    }
  }
  int temporaryArray[numChars] = {0};
  int inc = 0;
  for (int i = 0; i < 26; i++) {
    if (freq[i] == minFreq) {
      temporaryArray[inc] = i;
      inc++;
    }
  }
  for (int i = 0; i < numChars; i++) {
    if (i > 0) {
      cout << ", ";
    }
    if (i == numChars - 1) {
      cout << "and ";
    }
    cout << (char)('a' + temporaryArray[i]);
  }
  cout << endl;
}

// print freuency list
//  sort list from most frequent to least frequent
//  print out character
//  print out frequency
//  new line, repeat
void printFrequencyList(int *freq) {
  // Create two arrays: one to store characters and another to store frequencies
  char charArray[NUM_CHARS];
  int freqArray[NUM_CHARS];
  int numChars = 0;
  for (int i = 0; i < NUM_CHARS; i++) {
    if (freq[i] >= 0) {
      charArray[numChars] = 'a' + i;
      freqArray[numChars] = freq[i];
      numChars++;
    }
  }

  // Sort the two arrays in decreasing order of frequency using bubble sort
  bool swapped = true;
  while (swapped) {
    swapped = false;
    for (int i = 0; i < numChars - 1; i++) {
      if (freqArray[i] < freqArray[i + 1]) {
        // Swap frequency values
        int tempFreq = freqArray[i];
        freqArray[i] = freqArray[i + 1];
        freqArray[i + 1] = tempFreq;

        // Swap character values
        char tempChar = charArray[i];
        charArray[i] = charArray[i + 1];
        charArray[i + 1] = tempChar;

        swapped = true;
      } else if (freqArray[i] == freqArray[i + 1] &&
                 charArray[i] > charArray[i + 1]) {
        // Swap frequency values
        int tempFreq = freqArray[i];
        freqArray[i] = freqArray[i + 1];
        freqArray[i + 1] = tempFreq;

        // Swap character values
        char tempChar = charArray[i];
        charArray[i] = charArray[i + 1];
        charArray[i + 1] = tempChar;

        swapped = true;
      }
    }
  }

  // Print the character-frequency pairs
  for (int i = 0; i < 26; i++) {
    cout << charArray[i] << ": " << freqArray[i] << endl;
  }
}

void printBarChart(int *freq) {
  int maxFreq = 0;
  for (int i = 0; i < 26; i++) {
    if (freq[i] > maxFreq) {
      maxFreq = freq[i];
    }
  }

  for (int i = maxFreq; i > 0; i--) {
    cout << std::setw(2) << i << " ";
    for (int j = 0; j < 26; j++) {
      if (freq[j] >= i) {
        cout << "* ";
      } else {
        cout << "  ";
      }
    }
    cout << endl;
  }

  cout << "   ";
  for (int i = 0; i < 26; i++) {
    cout << (char)('a' + i) << " ";
  }
  cout << endl;
}
