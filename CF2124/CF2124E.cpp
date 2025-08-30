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
    int sum;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        sum=0;
        int a[n], presum[n], sufsum[n];
        for (int j=0; j<n; j++) {
            cin >> a[j];
            sum += a[j];
            presum[j]=sum;
        }
        sum=0;
        for (int j=n-1; j>=0; j++) {
            sum += a[j];
            sufsum[j]=sum;
        }
        if (i != t-1) {
            cout << endl;
        }
    }
    return 0;
}
