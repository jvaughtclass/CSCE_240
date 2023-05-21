// Copyright 2023 jvaught
// TrueFalseQuestion class implementation

#include "truefalsequestion.h"

#include <algorithm>
#include <string>

using namespace csce240_program5;

TrueFalseQuestion::TrueFalseQuestion(const std::string &question, bool answer)
    : Question(question), m_answer(answer) {}

TrueFalseQuestion::~TrueFalseQuestion() {}

bool TrueFalseQuestion::getAnswer() const { return m_answer; }

void TrueFalseQuestion::setAnswer(bool answer) { m_answer = answer; }

void TrueFalseQuestion::Print(bool showAnswer) const {
  Question::Print();
  if (showAnswer) {
    std::cout << "Correct Answer: " << (m_answer ? "true" : "false")
              << std::endl;
  }
}

// Implement the CheckAnswer function
bool TrueFalseQuestion::CheckAnswer(const std::string &answer) const {
  std::string lower_answer = answer;
  std::transform(lower_answer.begin(), lower_answer.end(), lower_answer.begin(),
                 ::tolower);
  return (lower_answer == "true" && m_answer) ||
         (lower_answer == "false" && !m_answer);
}
