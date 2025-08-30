#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
using namespace std;

int main() {
  // freopen("2019.in", "r", stdin);
  // freopen("2019.out", "w", stdout);
  int n;
  string S;
  cin >> S;
  n=S.size();
  int mods[2019];
  for (int i=0; i<2019; i++) {
    mods[i]=0;
  }
  mods[0]=1;
  int sumsofar=0;
  int pow10mod2019=1;
  for (int i=n-1; i>=0; i--) {
    sumsofar += pow10mod2019*(int(S[i])-48);
    sumsofar = sumsofar % 2019;
    mods[sumsofar]++;
    // cout << (int(S[i])-48) << " " << pow10mod2019 << " " << sumsofar << endl;
    pow10mod2019 = (10*pow10mod2019) % 2019;
  }
  int pairs=0;
  for (int i=0; i<2019; i++) {
    // cout << mods[i] << " ";
    pairs += (mods[i]*(mods[i]-1))/2;
  }
  cout << pairs;
}