#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    int t,n,k;
    string classes;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n >> k >> classes;
        int max_count=0;
        int last_important=-k-1;
        for (int j=0; j<n; j++) {
            if (classes[j]=='1') {
                last_important=j;
            }
            if (j-last_important>k) {
                max_count++;
            }
        }
        cout << max_count;
        if (i != t-1) {
            cout << endl;
        }
    }
}