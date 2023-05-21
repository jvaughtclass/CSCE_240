// Copyright 2023, jvaught
// This code is a program that takes in user input of three integers and two
// operators (arithmetic and relational). It then performs the arithmetic
// operation on the first two integers and compares the result to the third
// integer using the relational operator. If the comparison is true, the output
// is "Correct" and the number of correct answers is incremented. If the
// comparison is false, the output is "Incorrect". If the relational operator is
// not recognized, an error message is outputted. The program continues to run
// until the user exits.
#include <iomanip>   // import the input/output manipulation library
#include <iostream>  // import the input/output stream library
using std::cin;      // using the standard input
using std::cout;     // using the standard output
using std::endl;     // using the end line

int main() {
  int numCorrect = 0,
      totalExpressions =
          0;               // initialize numCorrect and totalExpressions with 0
  while (true) {           // infinite loop
    int num1, num2, num3;  // declare 3 integers
    char arithmeticOperator,
        relationalOperator;  // declare 2 operator characters
    cin >> num1 >> arithmeticOperator >> num2 >> relationalOperator >>
        num3;  // take input of the 3 integers and 2 operators from the user
    if (arithmeticOperator == '+') {    // check if arithmeticOperator is +
      if (relationalOperator == '>') {  // check if relationalOperator is >
        if (num1 + num2 >
            num3) {  // check if the result of num1 + num2 is greater than num3
          cout << num1 << " + " << num2 << " > " << num3
               << " - Correct"  // output the expression and result
               << endl;
          numCorrect++;  // increment numCorrect
        } else {
          cout << num1 << " + " << num2 << " > " << num3
               << " - Incorrect"  // output the expression and result
               << endl;
        }
      } else if (relationalOperator ==
                 '<') {  // check if relationalOperator is <
        if (num1 + num2 <
            num3) {  // check if the result of num1 + num2 is less than num3
          cout << num1 << " + " << num2 << " < " << num3
               << " - Correct"  // output the expression and result
               << endl;
          numCorrect++;  // increment numCorrect
        } else {
          cout << num1 << " + " << num2 << " < " << num3
               << " - Incorrect"  // output the expression and result
               << endl;
        }
      } else {
        cout << "Unrecognized relational operator "
             << relationalOperator  // output error message if relational
                                    // operator is not recognized
             << endl;
      }

    } else if (arithmeticOperator == '-') {
      if (relationalOperator == '>') {
        if (num1 - num2 > num3) {
          cout << num1 << " - " << num2 << " > " << num3 << " - Correct"
               << endl;
          numCorrect++;
        } else {
          cout << num1 << " - " << num2 << " > " << num3 << " - Incorrect"
               << endl;
        }
      } else if (relationalOperator == '<') {
        if (num1 - num2 < num3) {
          cout << num1 << " - " << num2 << " < " << num3 << " - Correct"
               << endl;
          numCorrect++;
        } else {
          cout << num1 << " - " << num2 << " < " << num3 << " - Incorrect"
               << endl;
        }
      } else {
        cout << "Unrecognized relational operator " << relationalOperator
             << endl;
      }
    } else if (arithmeticOperator == '*') {
      if (relationalOperator == '>') {
        if (num1 * num2 > num3) {
          cout << num1 << " * " << num2 << " > " << num3 << " - Correct"
               << endl;
          numCorrect++;
        } else {
          cout << num1 << " * " << num2 << " > " << num3 << " - Incorrect"
               << endl;
        }
      } else if (relationalOperator == '<') {
        if (num1 * num2 < num3) {
          cout << num1 << " * " << num2 << " < " << num3 << " - Correct"
               << endl;
          numCorrect++;
        } else {
          cout << num1 << " * " << num2 << " < " << num3 << " - Incorrect"
               << endl;
        }
      } else {
        cout << "Unrecognized relational operator " << relationalOperator
             << endl;
      }
    } else if (arithmeticOperator == '/') {
      if (relationalOperator == '>') {
        if (num1 / num2 > num3) {
          cout << num1 << " / " << num2 << " > " << num3 << " - Correct"
               << endl;
          numCorrect++;
        } else {
          cout << num1 << " / " << num2 << " > " << num3 << " - Incorrect"
               << endl;
        }
      } else if (relationalOperator == '<') {
        if (num1 / num2 < num3) {
          cout << num1 << " / " << num2 << " < " << num3 << " - Correct"
               << endl;
          numCorrect++;
        } else {
          cout << num1 << " / " << num2 << " < " << num3 << " - Incorrect"
               << endl;
        }
      } else {
        cout << "Unrecognized relational operator " << relationalOperator
             << endl;
      }
    } else if (arithmeticOperator == '%') {
      if (relationalOperator == '>') {
        if (num1 % num2 > num3) {
          cout << num1 << " % " << num2 << " > " << num3 << " - Correct"
               << endl;
          numCorrect++;
        } else {
          cout << num1 << " % " << num2 << " > " << num3 << " - Incorrect"
               << endl;
        }
      } else if (relationalOperator == '<') {
        if (num1 % num2 < num3) {
          cout << num1 << " % " << num2 << " < " << num3 << " - Correct"
               << endl;
          numCorrect++;
        } else {
          cout << num1 << " % " << num2 << " < " << num3 << " - Incorrect"
               << endl;
        }
      } else {
        cout << "Unrecognized relational operator " << relationalOperator
             << endl;
      }
    } else {
      cout << "Unrecognized arithmetic operator " << arithmeticOperator << endl;
    }
    totalExpressions++;
    char continueOrQuit;
    cin >> continueOrQuit;
    if (continueOrQuit == 'q') {
      break;
    }
  }

  double percentCorrect =
      static_cast<double>(numCorrect / totalExpressions) * 100;
  cout << std::setiosflags(std::ios::fixed | std::ios::showpoint)
       << std::setprecision(2);
  cout << numCorrect << " of " << totalExpressions << " = " << percentCorrect
       << "%" << endl;
  return 0;
}