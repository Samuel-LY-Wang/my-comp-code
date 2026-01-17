#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <numeric>
using namespace std;
#define ll long long
#define YES cout << "YES"
#define NO cout << "NO"

int mod(int a, int b) {
    return (a % b + b) % b;
}

bool isPossible(int a[], int n) {
    if (a[0] == 0) {
        return false;
    }
    else if (a[0] == 1) {
        return true;
    }
    else if (a[1] == 0) {
        return false;
    }
    else {
        return true;
    }
}

int main() {
    int t, n;
    int temp;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        int a[n];
        for (int j=0; j<n; j++) {
            a[j]=0;
        }
        for (int j=0; j<n; j++) {
            cin >> temp;
            a[temp]++;
        }
        if (isPossible(a, n)) {
            YES;
        } else {
            NO;
        }
        if (i != t-1) {
            cout << endl;
        }
    }
}