/*
get F[n] value of fibonacci series
n <= 45
*/
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <chrono>
using namespace std;
using namespace std::chrono;

// naive implementation
int fibonacci_naive(int n) {
    if (n <= 1)
        return n;
    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

// efficient implementation
int fibonacci_fast(int n) {
    int f[n+2];
    f[0] = 0;
    f[1] = 1;
    for (int i=2; i<=n; i++) {
        f[i] = f[i-1] + f[i-2];
    }
    return f[n];
}

// test function
void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}

// main function
int main() {
    // set params
    bool stress_test = false;
    bool use_naive = false;
    bool test_fast = false;
    bool use_fast = true;

    // stress test
    while (stress_test) {
        int n = (rand() % 45) + 1;

        auto s1 = high_resolution_clock::now();
        int res1 = fibonacci_naive(n);
        auto st1 = high_resolution_clock::now(); 
        auto d1 = duration_cast<microseconds>(st1 - s1); 

        auto s2 = high_resolution_clock::now(); 
        int res2 = fibonacci_fast(n);
        auto st2 = high_resolution_clock::now(); 
        auto d2 = duration_cast<microseconds>(st2 - s2); 

        if (res1 != res2) {
            cout << n << endl;
            cout << "\twrong answer: " << res1 << ", " << res2 << endl;
            break;
        }
        else {
            cout << n << " (" << res1 << " / " << res2 << ")" << "  -- OK " << endl;
            cout << "\t OK: \t time: (" << d1.count() << " / " << d2.count() << ")" << endl;
        }
    }

    // naive or fast solution
    if (use_naive || use_fast) {
        int a, b;
        cin >> a >> b;
        if (use_naive) {
        cout << fibonacci_naive(a, b) << endl;
        }
        if (use_fast) {
        cout << fibonacci_fast(a, b) << endl;
        }
    }

    // test_solution
    if (test_fast) {
        test_solution();
    }

    return 0;
}
