#ifndef TSWAP_H
#define TSWAP_H

template <typename T> void swap(T &first, T &second) {
  T temp = first;
  first = second;
  second = temp;
}

#endif // TSWAP_H