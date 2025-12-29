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
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        long long nums[n];
        long long presums[n];
        long long sufsums[n];
        for (int j=0; j<n; j++) {
            cin >> nums[j];
        }
        presums[0]=0;
        presums[1]=nums[0];
        sufsums[n-1]=0;
        for (int j=1; j<n-1; j++) {
            presums[j+1] = presums[j]+abs(nums[j]);
        }
        for (int j=n-2; j>-1; j--) {
            sufsums[j]=sufsums[j+1]-nums[j+1];
        }
        long long m = LLONG_MIN;
        for (int j=0; j<n; j++) {
            m = max(m, presums[j]+sufsums[j]);
        }
        cout << m;
        if (i != t-1) {
            cout << endl;
        }
    }
}