template <typename T> Array<T>::Array() : size_(0), storage_(new T[0]) {}

template <typename T>
Array<T>::Array(unsigned int n) : size_(n), storage_(new T[n]) {
  for (unsigned int i = 0; i < size_; i++) {
    storage_[i] = T();
  }
}

template <typename T> Array<T>::Array(const Array &other) : size_(other.size_) {
  storage_ = new T[size_];
  for (unsigned int i = 0; i < size_; i++) {
    storage_[i] = other.storage_[i];
  }
}

template <typename T> Array<T> &Array<T>::operator=(const Array &other) {
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

template <typename T> Array<T>::~Array() {
  if (storage_) {
    delete[] storage_;
  }
}

template <typename T>
const char *Array<T>::OutOfRangeException::what() const throw() {
  return "Array index out of range";
}

template <typename T> T &Array<T>::operator[](unsigned int index) {
  if (index >= size_) {
    throw OutOfRangeException();
  }
  return storage_[index];
}

template <typename T> unsigned int Array<T>::size() const { return size_; }
