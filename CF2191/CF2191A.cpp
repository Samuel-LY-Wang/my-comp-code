#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <numeric>
using namespace std;
#define ll long long
#define YES cout << "YES"
#define NO cout << "NO"

int mod(int a, int b) {
    return (a % b + b) % b;
}

bool isPossible(int a[], int n) {
    bool nEven = (n % 2 == 0);
    for (int i=0; i<n; i++) {
        if (!nEven && mod(a[i]-i, 2) == 0) {
            return false;
        }
        // cout << "a[i]: " << a[i] << " i: " << i << " (a[i]-i)%2: " << mod(a[i]-i, 2) << " a[0]%2: " << a[0]%2 << endl;
        if (nEven && mod(a[i]-i, 2) != a[0]%2) {
            return false;
        }
    }
    return true;
}

int main() {
    int t, n;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        int a[n];
        for (int j=0; j<n; j++) {
            cin >> a[j];
        }
        if (isPossible(a, n)) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        if (i != t-1) {
            cout << endl;
        }
    }
}