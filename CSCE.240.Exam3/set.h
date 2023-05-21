// Copyright 2023 CSCE240 (bhipp)
// Copyright 2023 jvaught

// Define our Set template class
// set - unordered (the order of the values doesn't matter) collection of
//       distinct objects (since the objects can be of any type - we'll make
//       this a template class
#ifndef _SET_H_
#define _SET_H_

#include <iostream>
using std::cout;
using std::endl;

namespace Project3Problem3 {

template <class TheType>
class Set {
 public:
  // default constructor
  explicit Set(int size = 0, const TheType* values = nullptr) {
    size_ = 0;
    values_ = nullptr;
    SetValues(size, values);
  }

  // copy constructor
  Set(const Set& to_copy) {
    size_ = 0;
    values_ = nullptr;
    SetValues(to_copy.size_, to_copy.values_);
  }

  // destructor
  ~Set() {
    if (values_ != nullptr) delete[] values_;
  }

  // assignment operator
  Set& operator=(const Set& to_copy) {
    SetValues(to_copy.size_, to_copy.values_);
    return *this;  // return the newly updated object the operator
                   // was called on
  }

  // SetValues function
  // pre-conditions the second argument points to a block of at least
  //                new_size TheTypes (currently not checking for
  //                duplicates)
  void SetValues(int new_size, const TheType* new_values) {
    if (new_size < 0) return;
    if (new_size != size_) {
      if (size_ != 0) delete[] values_;
      if (new_size == 0)
        values_ = nullptr;
      else
        values_ = new TheType[new_size];
    }
    size_ = new_size;
    int position = 0;
    for (int i = 0; i < size_; ++i) {
      bool already_in_there = false;
      for (int j = 0; j < position && !already_in_there; ++j)
        already_in_there = values_[j] == new_values[i];
      if (!already_in_there) values_[position++] = new_values[i];
    }
    size_ = position;
  }

  // Print function to display values at the standard output device
  void Print() const {
    cout << "{";
    for (int i = 0; i < size_; ++i)
      cout << values_[i] << (i < size_ - 1 ? ", " : "");
    cout << "}" << endl;
  }

  // Is a Subset of
  bool IsASubset(const Set& possible_subset) const {
    bool answer = true;
    int i = 0;
    while (answer && i < possible_subset.size_) {
      answer = false;
      for (int j = 0; j < size_ && !answer; ++j) {
        answer = values_[j] == possible_subset.values_[i];
      }
      ++i;
    }
    return answer;
  }

  // is an element of
  bool IsAnElementOf(const TheType& the_value) const {
    bool found = false;
    int i = 0;
    while (i < size_ && !found) found = values_[i++] == the_value;
    return found;
  }

  int GetCardinality() const { return size_; }

  Set Intersection(const Set& right) const {
    TheType* intersection_values = new TheType[size_];
    int intersection_size = 0;

    for (int i = 0; i < size_; ++i) {
      if (right.IsAnElementOf(values_[i])) {
        intersection_values[intersection_size++] = values_[i];
      }
    }

    Set<TheType> intersection_set(intersection_size, intersection_values);
    delete[] intersection_values;
    return intersection_set;
  }

  // Equality operator
  bool operator==(const Set& right) const {
    if (size_ != right.size_) {
      return false;
    }

    for (int i = 0; i < size_; ++i) {
      if (!right.IsAnElementOf(values_[i])) {
        return false;
      }
    }

    return true;
  }

 private:
  int size_;  // cardinality / cardinal number
  TheType* values_;
};  // class Set

}  // namespace Project3Problem3

#endif  // _SET_H
