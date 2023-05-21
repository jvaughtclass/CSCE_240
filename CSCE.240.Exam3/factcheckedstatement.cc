// Copyright 2023 jvaught

#include "factcheckedstatement.h"

namespace Project3Problem2 {
FactCheckedStatement::FactCheckedStatement(const std::string& statement,
                                           double truth)
    : Sentence(statement), truth_(0) {
  if (isValidStatement(statement)) {
    SetTruth(truth);
  } else {
    Sentence::operator=("This is an unverified statement.");
  }
}

FactCheckedStatement& FactCheckedStatement::operator=(
    const std::string& statement) {
  if (isValidStatement(statement)) {
    Sentence::operator=(statement);
    truth_ = 0;
  }
  return *this;
}

double FactCheckedStatement::GetTruth() const { return truth_; }

void FactCheckedStatement::SetTruth(double truth) {
  if (truth >= 0 && truth <= 1) {
    truth_ = truth;
  }
}

std::ostream& operator<<(std::ostream& os,
                         const FactCheckedStatement& statement) {
  os << statement.c_str() << " (" << statement.GetTruth() * 100 << "% true)";
  return os;
}

bool FactCheckedStatement::isValidStatement(const std::string& statement) {
  return !statement.empty() && std::isupper(statement[0]) &&
         statement.back() == '.';
}
}  // namespace Project3Problem2