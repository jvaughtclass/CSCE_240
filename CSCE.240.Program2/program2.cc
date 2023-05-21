// Copyright 2023 jvaught
// runs main function for programming assignment #2

#include <iostream>

#include "program2functions.h"

int main() {
  // Declare and input variables for two dates
  int month1, day1, year1, month2, day2, year2;
  char slash1, slash2;
  std::cin >> month1 >> slash1 >> day1 >> slash2 >> year1 >> month2 >> slash1 >>
      day2 >> slash2 >> year2;

  // Check if the two dates are valid
  if (!ValidDate(month1, day1, year1) || !ValidDate(month2, day2, year2)) {
    // If date 1 is not valid, print an error message
    if (!ValidDate(month1, day1, year1)) {
      std::cout << month1 << "/" << day1 << "/" << year1
                << " is not a valid date\n";
    }
    // If date 2 is not valid, print an error message
    if (!ValidDate(month2, day2, year2)) {
      std::cout << month2 << "/" << day2 << "/" << year2
                << " is not a valid date\n";
    }
    // Return 0 if the dates are not valid
    return 0;
  }

  // Calculate the number of days from date 1 to January 1 of the same year
  int dayCount1 = 0;
  for (int y = 1; y < year1; y++) {
    dayCount1 += LeapYear(y) ? 366 : 365;
  }
  for (int m = 1; m < month1; m++) {
    dayCount1 += LastDayOfMonth(m, year1);
  }
  dayCount1 += day1;

  // Calculate the number of days from date 2 to January 1 of the same year
  int dayCount2 = 0;
  for (int y = 1; y < year2; y++) {
    dayCount2 += LeapYear(y) ? 366 : 365;
  }
  for (int m = 1; m < month2; m++) {
    dayCount2 += LastDayOfMonth(m, year2);
  }
  dayCount2 += day2;

  // Calculate the difference between the two dates
  int diff = dayCount2 - dayCount1;

  // Print the difference between the two dates
  if (diff < 0) {
    std::cout << month1 << "/" << day1 << "/" << year1 << " is " << -diff
              << " days after " << month2 << "/" << day2 << "/" << year2
              << std::endl;
  } else if (diff > 0) {
    std::cout << month1 << "/" << day1 << "/" << year1 << " is " << diff
              << " days before " << month2 << "/" << day2 << "/" << year2
              << std::endl;
  } else {
    std::cout << month1 << "/" << day1 << "/" << year1 << " is 0 days before "
              << month2 << "/" << day2 << "/" << year2 << std::endl;
  }

  // Return 0 to indicate success
  return 0;
}
