#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i=0; i<t; i++) {
    long long n,m;
    cin >> n >> m;
    long long a[n];
    for (int j=0; j<n; j++) {
        cin >> a[j];
        a[j]=a[j]%m;
    }
    sort(a, a+n);
    long long minsum=n*m;
    for (int j=0; j<n; j++) {
        long long sum=0;
        for (int k=0; k<n; k++) {
            long long diff = abs(a[k]-a[j]);
            sum += min(diff, m-diff);
        }
        minsum=min(minsum, sum);
    }
    cout << minsum << endl;
  }
}
