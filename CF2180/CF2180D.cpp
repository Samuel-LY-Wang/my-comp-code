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
    int n;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        int x[n];
        for (int j=0; j<n; j++) {
            cin >> x[j];
        }
        int dist[n-1];
        for (int j=0; j<n-1; j++) {
            dist[j] = x[j+1]-x[j];
        }
        int temp = 0;
        int h = (n-1)/2;
        int l = (n-1)-h;
        int subs[l];
        int adds[h];
        for (int j=0; j<n-1; j++) {
            temp = dist[j]-temp;
            if (j%2==0) {
                subs[j/2] = temp;
            }
            else {
                adds[j/2] = -temp;
            }
        }
        // cout << l << " " << h << endl;
        sort(subs, subs+l);
        sort(adds, adds+h);
        // for (int j=0; j<l; j++) {
        //     cout << subs[j] << " ";
        // }
        // cout << endl;
        // for (int j=0; j<h; j++) {
        //     cout << adds[j] << " ";
        // }
        // cout << endl;
        int ptr1 = 0; // over subs
        int ptr2 = 0; // over adds
        int res = 0;
        for (int j=0; j<n; j++) {
            if (ptr1 > l || ptr2 > h) {
                break;
            }
            if (subs[l-ptr1-1] > adds[ptr2]) {
                res = max(res, l-ptr1+1+ptr2);
                ptr1++;
            }
            else {
                ptr2++;
            }
        }
        cout << res;
        if (i != t-1) {
            cout << endl;
        }
    }
}