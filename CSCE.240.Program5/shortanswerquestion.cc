// Copyright 2023 jvaught
// ShortAnswerQuestion class implementation

#include "shortanswerquestion.h"

#include <string>

using namespace csce240_program5;

ShortAnswerQuestion::ShortAnswerQuestion(const std::string &question,
                                         const std::string &answer)
    : Question(question), m_correctAnswer(answer) {}

ShortAnswerQuestion::~ShortAnswerQuestion() {}

std::string ShortAnswerQuestion::getCorrectAnswer() const {
  return m_correctAnswer;
}

void ShortAnswerQuestion::setCorrectAnswer(const std::string &answer) {
  m_correctAnswer = answer;
}

void ShortAnswerQuestion::Print(bool showAnswer) const {
  Question::Print();
  if (showAnswer) {
    std::cout << "Correct Answer: " << m_correctAnswer << std::endl;
  }
}
