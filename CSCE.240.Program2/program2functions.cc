// Copyright 2023 jvaught
// contains functions for programming assignment #2

#include "program2functions.h"

bool LeapYear(int year) {
  // Check if year is less than or equal to zero
  if (year <= 0) {
    // If year is not a valid year return false
    return false;
  }

  // Check if year is divisible by 4
  if (year % 4 == 0) {
    // Check if year is divisible by 100
    if (year % 100 == 0) {
      // Check if year is divisible by 400
      if (year % 400 == 0) {
        // If year is divisible by 4, 100, and 400 return true
        return true;
      }
      // If year is divisible by 4 and 100 but not 400 return false
      return false;
    }
    // If year is divisible by 4 but not 100 return true
    return true;
  }
  // If year is not divisible by 4 return false
  return false;
}

int LastDayOfMonth(int month, int year) {
  // Check if the month is not between 1 and 12
  if (month < 1 || month > 12) {
    // If month is not valid, return 0
    return 0;
  }

  // Check if month is February
  if (month == 2) {
    // Check if year is less than or equal to zero
    if (year <= 0) {
      // If year is not valid, return 0
      return 0;
    }

    // Check if year is a leap year
    if (LeapYear(year)) {
      // If year is a leap year return 29
      return 29;
    }
    // If year is not a leap year return 28
    return 28;
  }

  // Check if month is April, June, September, or November
  if (month == 4 || month == 6 || month == 9 || month == 11) {
    // If month is one of the above, return 30
    return 30;
  }

  // For all other months return 31
  return 31;
}

bool ValidDate(int month, int day, int year) {
  // If the year is less than or equal to 0, return false.
  if (year <= 0) {
    return false;
  }

  // Get the last day of the given month for the given year.
  int lastDay = LastDayOfMonth(month, year);

  // If the last day is 0 or if the day is less than 1 or greater than the last
  // day of the month, return false.
  if (lastDay == 0 || day < 1 || day > lastDay) {
    return false;
  }

  // Otherwise, return true.
  return true;
}

// NextDate function calculates the next date given the current month, day, and
// year
void NextDate(int &month, int &day, int &year) {
  // Check if the current date is valid
  if (!ValidDate(month, day, year)) {
    return;
  }

  // Increment the day by 1
  day++;

  // Check if the day is greater than the last day of the month
  if (day > LastDayOfMonth(month, year)) {
    // Reset day to 1 and increment the month by 1
    day = 1;
    month++;

    // Check if the month is greater than 12
    if (month > 12) {
      // Reset month to 1 and increment the year by 1
      month = 1;
      year++;
    }
  }
}

// PreviousDate function calculates the previous date given the current month,
// day, and year
void PreviousDate(int &month, int &day, int &year) {
  // Check if the current date is valid
  if (!ValidDate(month, day, year)) {
    return;
  }

  // Decrement the day by 1
  day--;

  // Check if the day is less than 1
  if (day < 1) {
    // Decrement the month by 1
    month--;

    // Check if the month is less than 1
    if (month < 1) {
      // Reset month to 12 and decrement the year by 1
      month = 12;
      year--;
    }

    // Set the day to the last day of the previous month
    day = LastDayOfMonth(month, year);
  }
}
