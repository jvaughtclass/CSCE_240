// Copyright 2023 jvaught
// MultipleChoiceQuestion class implementation

#include "multiplechoicequestion.h"

#include <string>

using namespace csce240_program5;

MultipleChoiceQuestion::MultipleChoiceQuestion(const std::string &question,
                                               int numChoices,
                                               std::string *choices,
                                               bool *correct)
    : Question(question),
      m_numChoices(numChoices),
      m_choices(nullptr),
      m_correct(nullptr) {
  SetAnswerChoices(numChoices, choices, correct);
}

MultipleChoiceQuestion::MultipleChoiceQuestion(
    const MultipleChoiceQuestion &other)
    : Question(other.GetQuestion()),
      m_numChoices(other.m_numChoices),
      m_choices(nullptr),
      m_correct(nullptr) {
  SetAnswerChoices(m_numChoices, other.m_choices, other.m_correct);
}

MultipleChoiceQuestion &MultipleChoiceQuestion::operator=(
    const MultipleChoiceQuestion &other) {
  if (this != &other) {
    Question::SetQuestion(other.GetQuestion());
    SetAnswerChoices(other.m_numChoices, other.m_choices, other.m_correct);
  }
  return *this;
}

MultipleChoiceQuestion::~MultipleChoiceQuestion() {
  delete[] m_choices;
  delete[] m_correct;
}

int MultipleChoiceQuestion::GetNumberOfChoices() const { return m_numChoices; }

void MultipleChoiceQuestion::SetNumberOfChoices(int numChoices) {
  m_numChoices = numChoices;
}

void MultipleChoiceQuestion::SetAnswerChoices(int numChoices,
                                              std::string *choices,
                                              bool *correct) {
  delete[] m_choices;
  delete[] m_correct;

  m_numChoices = numChoices;
  m_choices = new std::string[numChoices];
  m_correct = new bool[numChoices];

  for (int i = 0; i < numChoices; ++i) {
    if (choices) {
      m_choices[i] = choices[i];
    } else {
      m_choices[i] = "";
    }

    if (correct) {
      m_correct[i] = correct[i];
    } else {
      m_correct[i] = true;
    }
  }
}

void MultipleChoiceQuestion::Print(bool showAnswer) const {
  Question::Print();
  std::cout << "Answer Choices:" << std::endl;
  if (m_choices && m_correct) {
    for (int i = 0; i < m_numChoices; ++i) {
      std::cout << m_choices[i];
      if (showAnswer) {
        std::cout << (m_correct[i] ? " - correct" : " - incorrect");
      }
      std::cout << std::endl;
    }
  }
}
