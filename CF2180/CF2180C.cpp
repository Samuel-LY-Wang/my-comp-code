#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <numeric>
using namespace std;

long long largest_pow_two(long long n) {
    if (n <= 0) {
        return 0;
    }
    long long p = 1;
    while (2*p <= n) {
        p *= 2;
    }
    return p;
}

long long second_largest_pow_two(long long n) {
    return largest_pow_two(n - largest_pow_two(n));
}

int main() {
    long long t;
    long long n, k;
    cin >> t;
    for (long long i=0; i<t; i++) {
        cin >> n >> k;
        long long num_ns;
        if (k%2==0) {
            num_ns = k-2;
        }
        else {
            num_ns = k;
        }
        for (long long j=0; j<num_ns; j++) {
            cout << n << " ";
        }
        if (num_ns < k) {
            long long l = largest_pow_two(n);
            if (l == n) {
                cout << n << " " << 0;
            }
            else {
                long long sl = second_largest_pow_two(n);
                cout << ((2*sl-1)-(n-l)+l) << " " << (2*sl-1);
            }
        }
        if (i != t-1) {
            cout << endl;
        }
    }
}