#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
using namespace std;

int main() {
  int n,k;
  cin >> n >> k;
  int a[k], b[k];
  int reversea[n], reverseb[n];
  bool iscontained[n];
  for (int i=0; i<n; i++) {
    iscontained[i] = false;
    reversea[i]=-1;
    reverseb[i]=-1;
  }
  for (int i=0; i<k; i++) {
    cin >> a[i];
    reversea[a[i]-1]=i;
    iscontained[a[i]-1] = true;
  }
  for (int i=0; i<k; i++) {
    cin >> b[i];
    reverseb[b[i]-1]=i;
    iscontained[b[i]-1] = true;
  }
  int unrestricted=0;
  for (int i=0; i<n; i++) {
    if (!iscontained[i]) {
      unrestricted++;
    }
  }
  int frequencies[k];
  for (int i=0; i<k; i++) {
    frequencies[i]=0;
  }
  for (int i=0; i<n; i++) {
    if (reversea[i] != -1 && reverseb[i] != -1) {
      frequencies[(reverseb[i]+k-reversea[i]) % k]++;
    }
  }
  int antireverseb[n];
  for (int i=0; i<n; i++) {
    if (reverseb[i] == -1) {
      antireverseb[i]=-1;
    }
    else {
      antireverseb[i]=n-1-reverseb[i];
    }
  }
  int reversefrequencies[k];
  for (int i=0; i<k; i++) {
    reversefrequencies[i]=0;
  }
  for (int i=0; i<n; i++) {
    if (reversea[i] != -1 && antireverseb[i] != -1) {
      reversefrequencies[(antireverseb[i]+k-reversea[i]) % k]++;
    }
  }
  int maxnum=0;
  for (int i=0; i<k; i++) {
    maxnum=max(max(maxnum, frequencies[i]), reversefrequencies[i]);
  }
  cout << maxnum+unrestricted;
}