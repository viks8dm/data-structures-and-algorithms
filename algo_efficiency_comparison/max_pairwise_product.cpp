#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long MaxPairwiseProductTest(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            if ((long long)(numbers[first] * numbers[second]) > max_product) {
                max_product = (long long)(numbers[first] * numbers[second]);
            }
        }
    }

    return max_product;
}

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int l1 = 0, l2 = 0;
    int n = numbers.size();
    for (int i = 0; i<n; i++) {
        if (l1 <= numbers[i]) {
            l2 = l1;
            l1 = numbers[i];
        }
        else {
            if (l2 <= numbers[i]) {
                l2 = numbers[i];
            }
        }
    }
    max_product = (long long)l1 * l2;
    return max_product;
}

int main() {
    // stress test
    while (true) {
        int n = rand() % 1000 + 2;
        cout << n << endl;
        vector<int> v;
        for (int i = 0; i < n; i++){
            v.push_back(rand() % 1000000);
            cout << v[i] << " ";
        }
        cout << "\n";
        long long res1 = MaxPairwiseProduct(v);
        long long res2 = MaxPairwiseProductTest(v);
        if (res1 != res2) {
            cout << "Wrong ans: " << res1 << " " << res2 << endl;
            break;
        }
        else {
            cout << "OK\n";
        }
    }

    // main program section

    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
