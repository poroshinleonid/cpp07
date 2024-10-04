#ifndef TSWAP_HPP
#define TSWAP_HPP

template <typename T> void swap(T &first, T &second) {
  T temp = first;
  first = second;
  second = temp;
}

#endif // TSWAP_HPP