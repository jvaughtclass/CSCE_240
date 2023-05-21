// Copyright 2023 jvaught

#include <iostream>
#include <string>

#include "sentence.h"

namespace Project3Problem2 {
class FactCheckedStatement : public Sentence {
 public:
  FactCheckedStatement(const std::string& statement, double truth = 0);

  FactCheckedStatement& operator=(const std::string& statement);
  double GetTruth() const;
  void SetTruth(double truth);

  friend std::ostream& operator<<(std::ostream& os,
                                  const FactCheckedStatement& statement);

 private:
  double truth_;
  bool isValidStatement(const std::string& statement);
};
}  // namespace Project3Problem2
