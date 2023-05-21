// Copyright 2023 jvaught
// definition of the TrueFalseQuestion class

#ifndef TRUEFALSEQUESTION_H
#define TRUEFALSEQUESTION_H

#include <iostream>
#include <string>

#include "question.h"

namespace csce240_program5 {

class TrueFalseQuestion : public Question {
 public:
  explicit TrueFalseQuestion(const std::string &question = "?",
                             bool answer = true);
  virtual ~TrueFalseQuestion();

  bool getAnswer() const;
  void setAnswer(bool answer);

  // Make the Print function virtual and add the override keyword
  virtual void Print(bool showAnswer) const override;

  // Declare the CheckAnswer function
  virtual bool CheckAnswer(const std::string &answer) const override;

 private:
  bool m_answer;
};

}  // namespace csce240_program5

#endif  // TRUEFALSEQUESTION_H
