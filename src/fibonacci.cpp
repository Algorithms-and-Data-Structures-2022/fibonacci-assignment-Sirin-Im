#include "assignment/fibonacci.hpp"

#include <cmath>    // pow, sqrt, round
#include <cstdint>  // int64_t

namespace assignment {

  int64_t fib_binet(int n) {

    if (n <= 1) {
      return n;
    }

    double x1 = pow((1 + sqrt(5)) / 2, n);
    double x2 = pow((1  - sqrt(5)) / 2, n);
    return static_cast<int64_t>(round((x1 - x2) / sqrt(5)));
  }

  int64_t fib_iterative(int n) {

    if (n <= 1) {
      return n;
    }

    // буфер для хранения двух последних значения ряда Фибоначчи
    int64_t fib_prev = 0;
    int64_t fib_curr = 1;

    while (n > 1) {
      int64_t tmp  = fib_curr + fib_prev;
      fib_prev = fib_curr;
      fib_curr = tmp;
      n--;
    }

    return fib_curr;
  }

  int64_t fib_recursive(int n) {
    if (n == 0) {
      return 0;
    }
    if (n == 1) {
      return 1;
    }

    return fib_recursive(n-1) + fib_recursive(n-2);
  }

  int64_t fib_recursive_memoization(int n, std::vector<int64_t>& cache) {

    if (n <= 1) {
      return cache[n];
    }

    if (cache[n] != -1) {
      return cache[n];
    }

    cache[n] = fib_recursive_memoization(n-1, cache) + fib_recursive_memoization(n-2, cache);
    return cache[n];
  }

  int64_t fib_matrix(int n) {

    if (n <= 1) {
      return n;
    }

    Matrix2x2 matrix = FibMatrix;
    matrix = matrix_power(matrix,n);

    return matrix[0][1];
  }

}  // namespace assignment
