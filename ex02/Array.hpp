#ifndef ARRAY_H
#define ARRAY_H

#include <exception>

template <typename T> class Array {
public:
  Array();
  Array(unsigned int n);

  Array(const Array &other);
  Array &operator=(const Array &other);
  ~Array();

public:
  class OutOfRangeException : public std::exception {
    virtual const char *what() const throw();
  };

  T &operator[](unsigned int index);
  unsigned int size() const;

private:
  unsigned int size_;
  T *storage_;
};

#include "Array.tpp"

#endif
