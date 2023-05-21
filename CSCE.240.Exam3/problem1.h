// Copyright 2023 jvaught
// returns median of an array of integers
// if array has even number of elements, returns average of middle two
// if array has odd number of elements, returns middle element

#ifndef PROJECT3_PROBLEM1_PROBLEM1_H
#define PROJECT3_PROBLEM1_PROBLEM1_H

#include <algorithm>
#include <vector>

namespace Project3Problem1 {

/**
 * Returns the median of a given array. The array must be of type T.
 * @param arr const T* representing the array.
 * @param num_elements int representing the number of elements in the array.
 * @return T representing the median of the array.
 * @throws std::invalid_argument if num_elements is less than or equal to 0.
 */
template <typename T>
T Median(const T* arr, int num_elements) {
  // Check if num_elements is less than or equal to 0.
  if (num_elements <= 0) {
    // If so, throw an exception with the message "Invalid number of elements."
    throw std::invalid_argument("Invalid number of elements.");
  }

  // Copy arr into a vector called sorted_arr and sort its elements.
  std::vector<T> sorted_arr(arr, arr + num_elements);
  std::sort(sorted_arr.begin(), sorted_arr.end());

  // If there are an even number of elements, return the average of the middle
  // two.
  if (num_elements % 2 == 0) {
    return (sorted_arr[num_elements / 2 - 1] + sorted_arr[num_elements / 2]) /
           2;
  } else {
    // Otherwise, return the middle element.
    return sorted_arr[num_elements / 2];
  }
}

}  // namespace Project3Problem1

#endif  // PROJECT3_PROBLEM1_PROBLEM1_H
