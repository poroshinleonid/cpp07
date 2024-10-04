#ifndef TMAX_HPP
#define TMAX_HPP

template <typename T> T max(const T &a, const T &b) {
  if (a < b) {
    return b;
  }
  return a;
}

#endif // TMAX_HPP