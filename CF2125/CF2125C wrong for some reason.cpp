#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    long long validmods[48] = {1, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 121, 127, 131, 137, 139, 143, 149, 151, 157, 163, 167, 169, 173, 179, 181, 187, 191, 193, 197, 199, 209};
    long long totient = 48;
    int t;
    long long l,r;
    long long ans;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> l >> r;
        long long lmod=l%210;
        long long rmod=r%210;
        // cout << l%210 << " " << r%210 << " " << (r-l)/210;
        ans=(r-l)/210*totient;
        for (int j=0; j<totient; j++) {
            if (ans == 0) {
                if (validmods[j] >= lmod && validmods[j] <= rmod) {
                    ans += 1;
                }
            }
            else {
                if (validmods[j] >= lmod && validmods[j] <= rmod) {
                    ans += 1;
                }
                if (lmod >= rmod && (validmods[j] <= lmod || validmods[j] >= rmod)) {
                    ans += 1;
                }
            }
        }
        cout << ans;
        // logic
        if (i != t-1) {
            cout << endl;
        }
    }
    return 0;
}
