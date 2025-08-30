#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <numeric>
using namespace std;

long long multiples(long long l, long long r, long long div) {
    return r/div-(l+div-1)/div+1;
}

int main() {
    int t;
    long long l,r;
    long long ans;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> l >> r;
        long long lmod=l%210;
        long long rmod=r%210;
        // cout << l%210 << " " << r%210 << " " << (r-l)/210;
        ans=(r-l+1)-(multiples(l,r,2)+multiples(l,r,3)+multiples(l,r,5)+multiples(l,r,7));
        ans += (multiples(l,r,6)+multiples(l,r,10)+multiples(l,r,14)+multiples(l,r,15)+multiples(l,r,21)+multiples(l,r,35));
        ans -= (multiples(l,r,30)+multiples(l,r,42)+multiples(l,r,70)+multiples(l,r,105));
        ans += multiples(l,r,210);
        cout << ans;
        // logic
        if (i != t-1) {
            cout << endl;
        }
    }
    return 0;
}
