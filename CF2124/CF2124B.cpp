#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
using namespace std;

// int getmin(int arr[], int len) {
//     if (len == 2) {
//         return arr[0]+min(arr[0], arr[1]);
//     }
//     if (arr[1] == 0) {
//         return arr[0];
//     }
//     // len is the length of arr
//     return 0;
// }

int main() {
    int t;
    int n;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        int a[n];
        for (int j=0; j<n; j++) {
            cin >> a[j];
        }
        cout << a[0]+min(a[0], a[1]);
        // logic
        if (i != t-1) {
            cout << endl;
        }
    }
    return 0;
}
