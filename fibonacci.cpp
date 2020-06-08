/*
get F[n] value of fibonacci series
*/

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <chrono>
using namespace std;
using namespace std::chrono;

int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int fibonacci_fast(int n) {
    int f[n+2];

    f[0] = 0;
    f[1] = 1;
    for (int i=2; i<=n; i++) {
        f[i] = f[i-1] + f[i-2];
    }
    return f[n];
}

void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main() {
    // // stress test
    // while (true) {
    //     int n = (rand() % 45) + 1;

    //     auto s1 = high_resolution_clock::now();
    //     int res1 = fibonacci_naive(n);
    //     auto st1 = high_resolution_clock::now(); 
    //     auto d1 = duration_cast<microseconds>(st1 - s1); 

    //     auto s2 = high_resolution_clock::now(); 
    //     int res2 = fibonacci_fast(n);
    //     auto st2 = high_resolution_clock::now(); 
    //     auto d2 = duration_cast<microseconds>(st2 - s2); 

    //     if (res1 != res2) {
    //         cout << "wrong answer: " << res1 << ", " << res2 << endl;
    //         break;
    //     }
    //     else {
    //         cout << n << " (" << res1 << " / " << res2 << ")" << "  -- OK " << endl;
    //         cout << " time: (" << d1.count() << " / " << d2.count() << ")" << endl;
    //     }
    // }

    // main program
    int n = 0;
    std::cin >> n;

    // std::cout << fibonacci_naive(n) << '\n';
    // test_solution();
    std::cout << fibonacci_fast(n) << '\n';
    return 0;
}
