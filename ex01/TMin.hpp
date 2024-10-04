#ifndef TMIN_HPP
#define TMIN_HPP

template <typename T> T min(const T &a, const T &b) {
  if (a > b) {
    return b;
  }
  return a;
}

#endif // TMIN_HPP