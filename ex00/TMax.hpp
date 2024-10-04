#ifndef TMAX_H
#define TMAX_H

template <typename T> T max(const T &a, const T &b) {
  if (a < b) {
    return b;
  }
  return a;
}

#endif // TMAX_H