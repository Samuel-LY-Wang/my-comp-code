#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int t;
    int a, b, l;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> l >> a >> b;
        int g = gcd(l, b);
        cout << (l-g)+(a%g);
        if (i != t-1) {
            cout << endl;
        }
    }
}