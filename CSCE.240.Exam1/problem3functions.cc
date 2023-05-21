#include <iostream>
#include <sstream>
#include <string>
using std::istringstream;
using std::string;
using std::to_string;

int NumDigits(int num) {
  int digits = 0;
  if (num == 0) {
    return 1;
  }
  if (num < 0) {
    num = -num;
  }
  while (num > 0) {
    num /= 10;
    digits++;
  }
  return digits;
}

// A function to replace all occurrences of the `find` integer with the
// 'replace' integer, moving from right to left
bool FindAndReplace(int &num, int find, int replace) {
  int find_len = NumDigits(find);
  int replace_len = NumDigits(replace);
  int num_len = NumDigits(num);

  // Check if the preconditions are not met. If `find` or `replace` is negative,
  // or if the number of digits in `find` is less than `replace`, return false
  if (find_len < 0 || replace_len < 0 || find_len < replace_len) {
    return false;
  }
  // Convert the integers to strings
  string num_str = to_string(num);
  string find_str = to_string(find);
  string replace_str = to_string(replace);
  if (replace_len < find_len) {
    int numZeros = find_len - replace_len;
    replace_str = string(numZeros, '0') + replace_str;
  }

  // Loop through the `num` string from right to left
  for (int i = num_len - find_len; i >= 0; i--) {
    // If the substring of length `find_len` starting from position `i` is equal
    // to the `find` string
    if (num_str.substr(i, find_len) == find_str) {
      // Replace the substring with the `replace` string
      num_str.replace(i, find_len, replace_str);
    }
  }
  // Convert the modified string back to an integer and store it in `num`
  istringstream(num_str) >> num;
  return true;
}
