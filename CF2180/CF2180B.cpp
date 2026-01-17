#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <numeric>
using namespace std;

bool isSmaller(string a, string b) {
    for (int i=0; i<min(a.length(), b.length()); i++) {
        if ((int) a[i] < (int) b[i]) {
            return true;
        }
        else if ((int) a[i] > (int) b[i]) {
            return false;
        }
    }
    if (a.length() < b.length()) {
        return true;
    }
    return false;
}

string add_optimal(string a, string b) {
    string c = a+b;
    string d = b+a;
    if (isSmaller(c, d)) {
        return c;
    }
    else {
        return d;
    }
}

int main() {
    int t;
    int n;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        string s;
        string cur = "";
        for (int j=0; j<n; j++) {
            cin >> s;
            cur = add_optimal(cur, s);            
        }
        cout << cur;
        if (i != t-1) {
            cout << endl;
        }
    }
}