// Copyright 2023 jvaught
// definition of the ShortAnswerQuestion class

#ifndef SHORTANSWERQUESTION_H
#define SHORTANSWERQUESTION_H

#include <iostream>
#include <string>

#include "question.h"

namespace csce240_program5 {

class ShortAnswerQuestion : public Question {
 public:
  explicit ShortAnswerQuestion(const std::string &question = "?",
                               const std::string &answer = "");
  virtual ~ShortAnswerQuestion();

  std::string getCorrectAnswer() const;
  void setCorrectAnswer(const std::string &answer);

  virtual void Print(bool showAnswer) const override;
  virtual bool CheckAnswer(const std::string &answer) const override;

 private:
  std::string m_correctAnswer;
};

}  // namespace csce240_program5

#endif  // SHORTANSWERQUESTION_H