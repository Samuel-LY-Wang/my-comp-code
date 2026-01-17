#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    int n = 1000000000;
    int m = 0;
    for (int i=0; i<n; i++) {
        if (n^i < n && i+(n^i)>m) {
            m = i+(n^i);
        }
    }
    cout << m << endl;
    int a = 610612735;
    int b = 536870911;
    cout << (a^b) << " " << (a+b);
}
