#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a[n], b[n];
  long long answer=0;
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }
  for (int i=0; i<n; i++) {
    cin >> b[i];
  }
//   for (int i=0; i<n; i++) {
//     for (int j=0; j<=i; j++) {
//         if (a[j]==b[i-j]) {
//             answer += min(j+1, i-j+1);
//             // cout << i << " " << j << " " << a[j] << " " << min(j+1, i-j+1) << endl;
//         }
//     }
//   }
//   for (int i=1; i<n; i++) {
//     for (int j=i; j<n; j++) {
//         if (a[j]==b[n+i-j-1]) {
//             answer += min(j-i+1, n-j);
//             // cout << i << " " << j << " " << a[j] << " " << min(j-i+1, n-j) << endl;
//         }
//     }
//   }
//   for (int i=1; i<n; i++) {
//     if (a[i]==b[i]) {
//         answer += i*(i+1)+(n-i)*(n-i-1)/2;
//     }
//   }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (a[i]==b[j]) {
                answer += min(min(i+1,j+1),min(n-i,n-j));
                if (i==j) {
                    answer += i*(i+1)/2+(n-i)*(n-i-1)/2;
                }
            }
        }
    }
  cout << answer;
}