#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::isalpha;
using std::isdigit;
using std::string;

int main() {
  string input;
  int alphabet_count = 0, digit_count = 0;
  while (cin >> input) {
    if (input == "." || input == "?" || input == "!") {
      break;
    }
    for (char c : input) {
      if (isalpha(c)) {
        alphabet_count++;
      } else if (isdigit(c)) {
        digit_count++;
      }
    }
  }
  string alphabet_word = alphabet_count == 1 ? "character" : "characters";
  string digit_word = digit_count == 1 ? "digit" : "digits";
  cout << "Input sentence contains " << alphabet_count << " alphabetic "
       << alphabet_word << " and " << digit_count << " " << digit_word << "."
       << endl;
  return 0;
}