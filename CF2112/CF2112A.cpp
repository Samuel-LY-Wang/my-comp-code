#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    int a,x,y;
    for (int i=0; i<t; i++) {
        cin >> a >> x >> y;
        if (a > min(x,y) && a < max(x,y)) {
            cout << "NO";
        }
        else {
            cout << "YES";
        }
        if (i != t-1) {
            cout << endl;
        }
    }
}
