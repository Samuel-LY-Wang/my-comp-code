#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int solve(int arr[], int n) {
    int ans=1;
    int g;
    for (int i=1; i<n; i++) {
        g=gcd(arr[i-1], arr[i]);
        ans=lcm(ans, arr[i-1]/g);
    }
    return ans;
}

int main() {
    int t;
    int n;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        int a[n];
        for (int j=0; j<n; j++) {
            cin >> a[j];
        }
        cout << solve(a, n);
        // logic
        if (i != t-1) {
            cout << endl;
        }
    }
    return 0;
}
