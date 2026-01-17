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
#define IMPOSSIBLE cout << "-1";

void solve(int n, string s) {
    vector<int> depth;
    vector<int> effective_depth;
    int cur_depth = 0;
    for (int j=0; j<s.length(); j++) {
        if (s[j] == '(') {
            if (j != 0 && s[j-1] == ')') {
                effective_depth.push_back(depth[depth.size()-1]-cur_depth);
            }
            cur_depth++;
        }
        else {
            if (j != 0 && s[j-1] == '(') {
                depth.push_back(cur_depth);
            }
            cur_depth--;
        }
    }
    if (depth.size() == 1) {
        IMPOSSIBLE;
        return;
    }
    effective_depth.push_back(depth[depth.size()-1]-depth[depth.size()-2]+effective_depth[effective_depth.size()-1]);
    // test if depth and effective depth are correct
    int min_eff_depth = INT_MAX;
    bool possible = false;
    for (int j=1; j<depth.size(); j++) {
        if (depth[j] > depth[j-1]) {
            if (j==depth.size()-1 || depth[j]-effective_depth[j] == depth[j+1]-effective_depth[j+1]) {
                min_eff_depth = min(min_eff_depth, effective_depth[j-1]);
                possible = true;
            }
        }
    }
    if (!possible) {
        IMPOSSIBLE;
        return;
    }
    cout << n-2*min_eff_depth;
    return;
}

int main() {
    int t, n;
    string s;
    int temp;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n >> s;
        solve(n, s);
        if (i != t-1) {
            cout << endl;
        }
    }
}