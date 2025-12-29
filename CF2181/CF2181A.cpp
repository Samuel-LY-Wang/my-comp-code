#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    int t, n;
    string s;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n >> s;
        bool has_2026 = false;
        bool has_2025 = false;
        for (int j=0; j<=n-4; j++) {
            if (s.substr(j, 4) == "2026") {
                has_2026 = true;
            }
            if (s.substr(j, 4) == "2025") {
                has_2025 = true;
            }
        }
        if (has_2026 || !has_2025) {
            cout << 0;
        }
        else {
            cout << 1;
        }
        if (i != t-1) {
            cout << endl;
        }
    }
}