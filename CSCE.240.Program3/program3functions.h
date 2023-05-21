// Copyright 2023 jvaught
// Description: This program will read a file and output the most frequent
// characters, least frequent characters, frequency table, and bar chart.
#ifndef PROGRAM3FUNCTIONS_H
#define PROGRAM3FUNCTIONS_H

bool isAlphabetic(char c);

char toLowerCase(char c);

void updateFrequency(char c, int* freq);

void printMostFrequent(int* freq);

void printLeastFrequent(int* freq);

void printFrequencyList(int* freq);

void printBarChart(int* freq);

#endif
