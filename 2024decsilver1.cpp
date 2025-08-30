#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
using namespace std;

int main() {
  int t,n;
  cin >> t;
  for (int i=0; i<t; i++) {
    cin >> n;
    int cakesizes[n];
    for (int j=0; j<n; j++) {
        cin >> cakesizes[j];
    }
    vector<long long> prefixsums;
    prefixsums.push_back(0);
    long long sumsofar=0;
    for (int j=0; j<n; j++) {
        sumsofar += cakesizes[j];
        prefixsums.push_back(sumsofar);
    }
    long long bestelsie = 0;
    for (int j=0; j<n/2; j++) {
        bestelsie=max(bestelsie, prefixsums[j]-prefixsums[0]+prefixsums[n]-prefixsums[j+n/2+1]);
    }
    cout << prefixsums[n]-bestelsie << " " << bestelsie;
    if (i != t-1) {
        cout << endl;
    }
  }
}