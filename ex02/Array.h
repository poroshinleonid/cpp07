#ifndef ARRAY_H
#define ARRAY_H

template <typename T>
class Array {
public:
  Array();
  Array(unsigned int n);
  Array(const Array &other);
  Array &operator=(const Array &other);

  const unsigned int &size() const;

private:
  int size_;
  T *storage;
};

#endif