#include <iostream>
#include <string>
#include <cassert>
using namespace std;

/********************************/
int get_num(const char c) {
    if (c=='I') { return 1; }
    if (c=='V') { return 5; }
    if (c=='X') { return 10; }
    if (c=='L') { return 50; }
    if (c=='C') { return 100; }
    if (c=='D') { return 500; }
    if (c=='M') { return 1000; }
    return -1;
}
    
/********************************/
int romanToInt(string s) {
    int out_val = 0;
    for (int i=0; i<s.length(); i++) {
        if (i==0) {
            out_val = get_num(s[i]);
            continue;
        }
        else if (((s[i]=='X') || s[i]=='V') && (s[i-1]=='I')) {
            out_val -= 2*get_num(s[i-1]);
        }
        else if (((s[i]=='L') || s[i]=='C') && (s[i-1]=='X')) {
            out_val -= 2*get_num(s[i-1]);
        }
        else if (((s[i]=='D') || s[i]=='M') && (s[i-1]=='C')) {
            out_val -= 2*get_num(s[i-1]);
        }
        
        out_val += get_num(s[i]);
    }
    
    return out_val;
}

/********************************/
void test_solution() {
    assert(3 == romanToInt("III"));
    assert(4 == romanToInt("IV"));
    assert(9 == romanToInt("IX"));
    assert(58 == romanToInt("LVIII"));
    assert(1994 == romanToInt("MCMXCIV"));

    cout << "ALL TESTS PASSED" << endl;
    return;
}

/********************************/
int main() {
    // test = true--> check test cases
    // test = false--> get user input
    bool test = false;

    if (test) {
        test_solution();
    }
    else {
        string s;
        cin >> s;
        cout << s << " = " << romanToInt(s) << endl;
    }

    return 0;
}