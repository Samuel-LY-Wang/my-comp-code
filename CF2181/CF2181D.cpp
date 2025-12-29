#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <numeric>
using namespace std;

// long long bashmodinv(long long a, long long mod) {
//     for (long long x=1; x<mod; x++) {
//         if ((a*x)%mod == 1) {
//             return x;
//         }
//     }
//     return -1;
// }

// long long fastmodinv(long long a, long long mod) {
//     // quickly gets modular inverse of a modulo mod
//     if (a==1) {
//         return 1;
//     }
//     long long m = mod%a;
//     long long b = bashmodinv(m, a);
//     long long ans = (mod*b+1)/a;
//     return ans%mod;
// }

long long permute(long long n, long long k, long long mod = 998244353) {
    // returns number of valid offsets
    // assumes n is len of a and b
    if (k > n) {
        return 0;
    }
    long long ans = 1;
    for (long long i=0; i<k; i++) {
        ans = (ans * (n-i)) % mod;
        // cout << "i=" << i << " ans=" << ans << endl;
    }
    // cout << n << " choose " << k << " is " << ans << endl;
    return ans;
}

long long fact(long long n, long long mod = 998244353) {
    if (n<0) {
        return 0;
    }
    long long ans = 1;
    for (long long i=2; i<=n; i++) {
        ans = (ans * i) % mod;
    }
    return ans;
}

int main() {
    long long mod = 998244353;
    long long t, n;
    cin >> t;
    for (long long i=0; i<t; i++) {
        long long ans = 0;
        cin >> n;
        long long num_0;
        long long nums[n];
        cin >> num_0;
        for (long long j=0; j<n; j++) {
            cin >> nums[j];
        }
        long long mx = 0;
        long long maxes = 0;
        long long sum = 0;
        for (long long j=0; j<n; j++) {
            mx = max(mx, nums[j]);
            sum += nums[j];
        }
        for (long long j=0; j<n; j++) {
            if (nums[j] == mx) {
                maxes++;
            }
        }
        // cout << "mx=" << mx << " maxes=" << maxes << " sum=" << sum << endl;
        long long m = n*mx - num_0 - sum;
        if (m<0) {
            m=0;
        }
        // cout << n << " " << m << endl;
        // m determines where the last max can go
        for (long long j=0; j<n-m; j++) {
            // cout << "Last max at position " << j << endl;
            long long to_add = 1;
            to_add = (to_add * fact(n - maxes)) % mod; // permute non-maxes
            to_add = (to_add * permute(j, maxes - 1)) % mod; // permute maxes before last max
            to_add = (to_add * maxes) % mod; // figure out which max is last
            ans = (ans + to_add) % mod;
            // cout << "Ans currently " << ans << endl;
        }
        cout << ans;
        if (i != t-1) {
            cout << endl;
        }
    }
}