/*
find least common multiple (LCM) of two numbers
0 <= a, b <= 1e7
*/
#include <iostream>
#include <cassert>
#include <chrono>
using namespace std;
using namespace std::chrono;

// naive implementation
long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

// helper function
int gcd_fast(int a, int b) {
  if (b == 0) {
    return a;    
  }
  int rem = a % b;
  return (gcd_fast(b, rem));
}
// efficient implementation
long long lcm_fast(int a, int b) {
  return ((long long)a*(long long)b)/(long long)gcd_fast(a,b);
}

// test function
void test_solution() {
  assert(lcm_fast(6, 8) == 24);
  assert(lcm_fast(761457, 614573) == 467970912861);
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
    int res1 = lcm_naive(a, b);
    auto st1 = high_resolution_clock::now(); 
    auto d1 = duration_cast<microseconds>(st1 - s1); 

    auto s2 = high_resolution_clock::now(); 
    int res2 = lcm_fast(a, b);
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
      cout << lcm_naive(a, b) << endl;
    }
    if (use_fast) {
      cout << lcm_fast(a, b) << endl;
    }
  }

  // test_solution
  if (test_fast) {
    test_solution();
  }

  return 0;
}
