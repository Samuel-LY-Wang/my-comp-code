#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int solve(int a, int b) {
    // returns max
    int temp=1;
    int ans=0;
    while (true) {
        a -= temp;
        if (a<0) {
            break;
        }
        ans++;
        temp *= 2;
        b -= temp;
        if (b<0) {
            break;
        }
        ans++;
        temp *= 2;
    }
    return ans;
}

int main() {
    int t;
    int a,b;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> a >> b;
        cout << max(solve(a,b), solve(b,a));
        if (i != t-1) {
            cout << endl;
        }
    }
}