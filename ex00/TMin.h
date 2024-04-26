#ifndef TMIN_H
#define TMIN_H

template <typename T> T min(const T &a, const T &b) {
  if (a > b) {
    return b;
  }
  return a;
}

#endif // TMIN_H