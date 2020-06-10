/*
last digit of large Fibonacci number <= 1e7
*/
#include <iostream>
#include <cmath>
#include <cassert>
#include <chrono>
using namespace std;
using namespace std::chrono;

// naive implementation
int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long tmp_previous = 0;

    for (int i = 0; i < n - 1; ++i) {
        tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current);
    }

    return (int)(current % 10);
}

// efficient implementation
int get_fibonacci_last_digit_fast(int n) {
    if (n <= 1)
        return n;

    int m = 0, val = 0;
    int vm = 0;
    int vm1 = 0;
    if (n%2 == 0) {
        m = n / 2;
        vm1 = get_fibonacci_last_digit_fast(m-1);
        vm = get_fibonacci_last_digit_fast(m);
        val = ((2 * vm1 + vm) * vm) % 10;
    }
    else {
        m = (n+1) / 2;
        vm1 = get_fibonacci_last_digit_fast(m-1);
        vm = get_fibonacci_last_digit_fast(m);
        val = ((int)pow(vm, 2) + (int)pow(vm1, 2)) % 10;
    }

    return val;
}

void test_solution() {
    assert(get_fibonacci_last_digit_fast(3) == 2);
    assert(get_fibonacci_last_digit_fast(10) == 5);
    for (int n = 0; n < 20; ++n)
        assert(get_fibonacci_last_digit_fast(n) == get_fibonacci_last_digit_naive(n));
}

int main() {
    // set params
    bool stress_test = true;
    bool use_naive = false;
    bool test_fast = false;
    bool use_fast = false;
    
    // stress test
    while (stress_test) {
        int n = (rand() % 45) + 1;

        auto s1 = high_resolution_clock::now();
        int res1 = get_fibonacci_last_digit_naive(n);
        auto st1 = high_resolution_clock::now(); 
        auto d1 = duration_cast<microseconds>(st1 - s1); 

        auto s2 = high_resolution_clock::now(); 
        int res2 = get_fibonacci_last_digit_fast(n);
        auto st2 = high_resolution_clock::now(); 
        auto d2 = duration_cast<microseconds>(st2 - s2); 

        if (res1 != res2) {
            cout << n << "\t wrong answer: " << res1 << ", " << res2 << endl;
            break;
        }
        else {
            cout << n << " (" << res1 << " / " << res2 << ")" << "  -- OK " << endl;
            cout << " time: (" << d1.count() << " / " << d2.count() << ")" << endl;
        }
    }

    // naive or fast solution
    if (use_naive || use_fast) {
        int n;
        cin >> n;
        if (use_naive) {
        cout << get_fibonacci_last_digit_naive(n) << endl;
        }
        if (use_fast) {
        cout << get_fibonacci_last_digit_fast(n) << endl;
        }
    }

    // test_solution
    if (test_fast) {
        test_solution();
    }

    return 0;
}
