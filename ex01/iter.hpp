#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename U> void iter(T arr[], int len, U func) {
  for (int i = 0; i < len; i++) {
    func(arr[i]);
  }
}

#endif // ITER_HPP