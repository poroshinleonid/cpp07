#ifndef ARRAY_H
#define ARRAY_H

#include <exception>

template <typename T> class Array {
public:
  Array() : size_(0), storage_(new T[0]) {}
  Array(unsigned int n) : size_(n), storage_(new T[n]) {
    for (unsigned int i = 0; i < size_; i++) {
      storage_[i] = T();
    }
  }

public:
  Array(const Array &other) : size_(other.size_) {
    storage_ = new T[size_];
    for (unsigned int i = 0; i < size_; i++) {
      storage_[i] = other.storage_[i];
    }
  }

  Array &operator=(const Array &other) {
    if (this != &other) {
      size_ = other.size_;
      delete[] storage_;
      storage_ = new T[size_];
      for (unsigned int i = 0; i < size_; i++) {
        storage_[i] = other.storage_[i];
      }
    }
    return *this;
  }
  ~Array() {
    if (storage_) {
      delete[] storage_;
    }
  }

public:
  class OutOfRangeException : public std::exception {
    virtual const char *what() const throw() { return "Index out of range"; }
  };

  T &operator[](unsigned int index) {
    if (index >= size_) {
      throw OutOfRangeException();
    }
    return storage_[index];
  }

  unsigned int size() const { return size_; }

private:
  unsigned int size_;
  T *storage_;
};

#endif