/*
find greatest common divisor of two functions
*/
#include <iostream>
#include <cassert>
#include <chrono>
using namespace std;
using namespace std::chrono;

// naive implementation
int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

// efficient implementation
int gcd_fast(int a, int b) {
  if (b == 0) {
    return a;    
  }
  int rem = a % b;
  return (gcd_fast(b, rem));
}

// test function
void test_solution() {
  assert(gcd_fast(18, 35) == 1);
  assert(gcd_fast(28851538, 1183019) == 17657);
}

// main function
int main() {
  bool stress_test = true;

  // stress test
  while (stress_test) {
    int a = (rand() % 2000000000) + 1;
    int b = (rand() % 2000000000) + 1;

    auto s1 = high_resolution_clock::now();
    int res1 = gcd_naive(a, b);
    auto st1 = high_resolution_clock::now(); 
    auto d1 = duration_cast<microseconds>(st1 - s1); 

    auto s2 = high_resolution_clock::now(); 
    int res2 = gcd_fast(a, b);
    auto st2 = high_resolution_clock::now(); 
    auto d2 = duration_cast<microseconds>(st2 - s2);

    if (res1 != res2) {
      cout << "(" << a << ", " << b << ")    (" << res1 << " / " << res2 << ")" << endl;
      cout << "\t wrong answer: " << res1 << ", " << res2 << endl;
      break;
    }
    else {
      cout << "(" << a << ", " << b << ")    (" << res1 << " / " << res2 << ")" << endl;
      cout << "\t OK: " << " time: (" << d1.count() << " / " << d2.count() << ")" << endl;
    }
  }

  // main programs
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_naive(a, b) << std::endl;
  test_solution();
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
