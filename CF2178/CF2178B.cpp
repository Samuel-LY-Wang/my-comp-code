#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int solve(string s, int n) {
    bool leading_s = (s[0]=='s');
    bool trailing_s = (s[n-1]=='s');
    bool contains_s = false;
    int cur_run = 0;
    vector<int> u_runs;
    for (int j=0; j<n; j++) {
        if (s[j]=='s') {
            contains_s = true;
            if (cur_run>0) {
                u_runs.push_back(cur_run);
            }
            cur_run=0;
        }
        else {
            cur_run++;
            if (j==n-1) {
                u_runs.push_back(cur_run);
            }
        }
    }
    if (!contains_s) {
        return (n+2)/2;
    }
    int l = u_runs.size();
    int ct = 0;
    for (int i=0; i<l; i++) {
        if ((i==0 && !leading_s)|| (i==l-1 && !trailing_s)) {
            ct+=(u_runs[i]+1)/2;
        }
        else {
            ct+=int((u_runs[i])/2);
        }
    }
    return ct;
}

int main() {
    int t;
    string s;
    vector<int> u_runs;
    cin >> t;
    for (int i=0; i<t; i++) {
        u_runs.clear();
        cin >> s;
        int n=s.length();
        cout << solve(s, n);
        if (i != t-1) {
            cout << endl;
        }
    }
}