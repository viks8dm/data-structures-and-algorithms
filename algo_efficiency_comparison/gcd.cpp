/*
find greatest common divisor (GCD) of two numbers
0 <= a, b <= 1e7
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
  // set params
  bool stress_test = false;
  bool use_naive = false;
  bool test_fast = false;
  bool use_fast = true;

  // stress test
  while(stress_test) {
    int a = (rand() % 10000000) + 1;
    int b = (rand() % 10000000) + 1;

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

  // naive or fast solution
  if (use_naive || use_fast) {
    int a, b;
    cin >> a >> b;
    if (use_naive) {
      cout << gcd_naive(a, b) << endl;
    }
    if (use_fast) {
      cout << gcd_fast(a, b) << endl;
    }
  }

  // test_solution
  if (test_fast) {
    test_solution();
  }

  return 0;
}
