// Copyright 2023 jvaught
// definition of the MultipleChoiceQuestion class

#ifndef MULTIPLECHOICEQUESTION_H
#define MULTIPLECHOICEQUESTION_H

#include <iostream>
#include <string>

#include "question.h"
using std::string;

namespace csce240_program5 {

class MultipleChoiceQuestion : public Question {
 public:
  explicit MultipleChoiceQuestion(const std::string &question = "?",
                                  int numChoices = 0,
                                  std::string *choices = nullptr,
                                  bool *correct = nullptr);
  MultipleChoiceQuestion(const MultipleChoiceQuestion &other);
  MultipleChoiceQuestion &operator=(const MultipleChoiceQuestion &other);
  virtual ~MultipleChoiceQuestion();

  int GetNumberOfChoices() const;
  void SetNumberOfChoices(int numChoices);

  void SetAnswerChoices(int numChoices, std::string *choices, bool *correct);

  virtual void Print(bool showAnswer) const override;
  virtual bool CheckAnswer(const std::string &answer) const override;

 private:
  int m_numChoices;
  std::string *m_choices;
  bool *m_correct;
};

}  // namespace csce240_program5

#endif  // MULTIPLECHOICEQUESTION_H
