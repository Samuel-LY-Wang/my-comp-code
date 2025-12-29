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

int greedycoin(long long coins[], long long n, long long k) {
    // returns number of coins used to make k
    int ans = 0;
    for (long long i=0; i<n; i++) {
        while (k >= coins[i]) {
            k -= coins[i];
            ans++;
        }
    }
    return ans;
}

int main() {
    long long t, n, m, k;
    cin >> t;
    for (long long i=0; i<t; i++) {
        cin >> n >> m >> k;
        map<long long, vector<long long> > zytox;
        vector<long long> temp;
        long long x, y, z;
        long long presentx[m];
        long long zy[n];
        for (int j=0; j<m; j++) {
            cin >> presentx[j];
        }
        for (long long j=0; j<n; j++) {
            cin >> x >> y >> z;
            k -= y;
            zy[j] = z - y;
            if (zytox.find(z-y) == zytox.end()) {
                temp.push_back(x);
                zytox[z-y] = temp;
                temp.clear();
            }
            else {
                zytox[z-y].push_back(x);
            }
        }
        for (map<long long, vector<long long> >::iterator it=zytox.begin(); it!=zytox.end(); it++) {
            sort(zytox[it->first].begin(), zytox[it->first].end(), greater<long long>());
        }
        sort(zy, zy+n);
        int ind = greedycoin(zy, n, k);
        vector<long long> xes;
        for (int j=ind; j<n; j++) {
            long long x = zytox[zy[j]].back();
            zytox[zy[j]].pop_back();
            xes.push_back(x);
        }
        sort(xes.begin(), xes.end());
    }
}