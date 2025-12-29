#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <numeric>
using namespace std;

long long bash(int a[], int b[], int n) {
    // returns number of valid offsets
    // assumes n is len of a and b
    long long ans = 0;
    for (int offset=0; offset<n; offset++) {
        bool valid = true;
        for (int i=0; i<n; i++) {
            if (a[i] >= b[(i+offset)%n]) {
                valid = false;
                break;
            }
        }
        if (valid) {
            ans++;
        }
    }
    return ans;
}

int main() {
    int t, n;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        int a[n];
        int b[n];
        int c[n];
        for (int j=0; j<n; j++) {
            cin >> a[j];
        }
        for (int j=0; j<n; j++) {
            cin >> b[j];
        }
        for (int j=0; j<n; j++) {
            cin >> c[j];
        }
        cout << n*bash(a,b,n)*bash(b,c,n);
        if (i != t-1) {
            cout << endl;
        }
    }
}