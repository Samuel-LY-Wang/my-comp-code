#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    int n;
    bool ispossible;
    int minops;
    for (int i=0; i<t; i++) {
        ispossible=false;
        cin >> n;
        int a[n];
        int diff[n-1];
        for (int j=0; j<n; j++) {
            cin >> a[j];
            diff[j-1]=a[j]-a[j-1];
        }
        for (int j=0; j<n-2; j++) {
            if (diff[j+1]<0 && diff[j]>0) {
                minops=1;
                ispossible=true;
            }
            if (diff[j+1]>0 && diff[j]<0) {
                minops=1;
                ispossible=true;
            }
        }
        for (int j=0; j<n-1; j++) {
            if (diff[j] <= 1 && diff[j] >= -1) {
                minops=0;
                ispossible=true;
            }
        }
        if (ispossible) {
            cout << minops;
        }
        else {
            cout << -1;
        }
        if (i != t-1) {
            cout << endl;
        }
    }
}
