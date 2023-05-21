// Copyright 2023 jvaught
// TrueFalseQuestion class implementation

#include "truefalsequestion.h"

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
