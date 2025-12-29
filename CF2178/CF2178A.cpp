#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    int t;
    string s;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> s;
        int n=s.length();
        int num_ys = 0;
        for (int j=0; j<n; j++) {
            if (s[j]=='Y') {
                num_ys++;
            }
        }
        if (num_ys < 2) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        if (i != t-1) {
            cout << endl;
        }
    }
}