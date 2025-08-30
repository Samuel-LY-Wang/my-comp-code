#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
using namespace std;

int dec_index(int arr[], int len) {
    for (int i=1; i<len; i++) {
        if (arr[i-1] > arr[i]) {
            return i;
        }
    }
    return -1;
}

int main() {
    int t;
    int n;
    int temp;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        int a[n];
        for (int j=0; j<n; j++) {
            cin >> a[j];
        }
        temp=dec_index(a, n);
        if (temp == -1) {
            cout << "NO";
        }
        else {
            cout << "YES" << endl;
            cout << "2" << endl;
            cout << a[temp-1] << " " << a[temp];
        }
        // logic
        if (i != t-1) {
            cout << endl;
        }
    }
    return 0;
}
