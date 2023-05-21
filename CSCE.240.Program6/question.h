// Copyright 2023 jvaught
// definition of the Question base class
#ifndef _QUESTION_H_
#define _QUESTION_H_

#include <string>
using std::string;
#include <iostream>

namespace csce240_program5 {

class Question {
 public:
  explicit Question(string q = "?") { question_ = q; }

  // Make the destructor virtual
  virtual ~Question() {}

  void SetQuestion(string q) {
    if (q.length() > 0) question_ = q;
  }
  string GetQuestion() const { return question_; }

  // Make the Print function virtual
  virtual void Print(bool showAnswer = false) const {
    std::cout << "Question: " << question_ << std::endl;
  }

  // Add a pure virtual CheckAnswer function
  virtual bool CheckAnswer(const string& answer) const = 0;

 private:
  string question_;
};

}  // namespace csce240_program5

#endif  // _QUESTION_H_
