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
  int intable[n][n];
  int numofeach[2*n+1];
  // vector<int> order;
  int replacement[2*n+1];
  int two=0,twon=0;
  for (int i=0; i<2*n+1; i++) {
    numofeach[i]=0;
    replacement[i]=0;
  }
  if (n==1) {
    cout << 2;
  }
  else {
    for (int i=0; i<n; i++) {
      for (int j=0; j<n; j++) {
          cin >> intable[i][j];
          numofeach[intable[i][j]]++;
      }
    }
    for (int i=2; i<2*n+1; i++) {
      if (numofeach[i] == 1 && two==0) {
        two=i;
      }
      else if (numofeach[i]==1) {
        twon=i;
      }
    }
    int postwox, postwoxn;
    for (int i=0; i<n; i++) {
      for (int j=0; j<n; j++) {
        if (two==intable[i][j]) {
          postwox=i;
        }
        if (twon==intable[i][j]) {
          postwoxn=i;
        }
      }
    }
    for (int i=0; i<n; i++) {
      replacement[intable[postwox][i]]=numofeach[intable[postwox][i]]+1;
      replacement[intable[postwoxn][i]]=2*n-numofeach[intable[postwoxn][i]]+1;
    }
    if (replacement[intable[0][0]] > n+1) {
      for (int i=2; i<2*n+1; i++) {
        replacement[i]=2*n+2-replacement[i];
      }
    }
    else if (replacement[intable[0][0]] == n+1 && replacement[intable[0][1]] > n+1) {
      for (int i=2; i<2*n+1; i++) {
        replacement[i]=2*n+2-replacement[i];
      }
    }
    // cout << endl;
    for (int i=0; i<n; i++) {
      for (int j=0; j<n; j++) {
          cout << replacement[intable[i][j]];
          if (j != n-1) {
              cout << " ";
          }
      }
      if (i != n-1) {
          cout << endl;
      }
    }
  }
//   for (int i=0; i<2*n+1; i++) {
//     cout << replacement[i] << " ";
//   }
}
