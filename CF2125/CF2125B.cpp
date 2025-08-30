#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int solve(long long a, long long b, long long k) {
    long long g=gcd(a,b);
    long long newa=a/g;
    long long newb=b/g;
    if (newa<=k && newb<=k) {
        return 1;
    }
    return 2;
}

int main() {
    int t;
    long long a,b,k;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> a >> b >> k;
        cout << solve(a,b,k);
        // logic
        if (i != t-1) {
            cout << endl;
        }
    }
    return 0;
}
