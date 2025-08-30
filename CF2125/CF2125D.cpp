#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <numeric>
using namespace std;

long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

long long eval(long long numerator, long long denominator, long long modulus) {
    long long den=power(denominator, modulus-2, modulus);
    return (den*numerator)%modulus;
}

int main() {
    long long m,n;
    long long mod=998244353;
    cin >> n >> m;
    long long params[n][4];
    // params[a][0]=l
    // params[a][1]=r
    // params[a][2]=p
    // params[a][3]=q
    for (int i=0; i<n; i++) {
        cin >> params[i][0] >> params[i][1] >> params[i][2] >> params[i][3];
    }
    // sort params by [i][1]
    // then do something related to dp I guess idk
    return 0;
}
