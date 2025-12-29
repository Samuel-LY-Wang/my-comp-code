#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <cmath>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        cout << "? " << 1 << " " << n << endl;
        cout.flush();
        long long total_sum;
        cin >> total_sum;
        if (total_sum == -1) {
            exit(1);
        }
        long long left = 1;
        long long right = n;
        long long int_left = 1;
        long long int_right = n;
        long long des_sum = total_sum/2;
        long long cur_sum=0;
        while (right>left) {
            long long mid = (left+right)/2;
            cout << "? " << int_left << " " << mid << endl;
            cout.flush();
            cin >> cur_sum;
            if (cur_sum == -1) {
                exit(1);
            }
            if (cur_sum == des_sum) {
                des_sum /= 2;
                if (int_right-mid <= mid-int_left) {
                    left = mid+1;
                    int_left = left;
                    right = int_right;
                }
                else {
                    right = mid;
                    int_right = right;
                    left = int_left;
                }
            }
            else if (cur_sum < des_sum) {
                left = mid+1;
            }
            else {
                right = mid;
            }
        }
        cout << "? " << left << " " << right << endl;
        cout.flush();
        cin >> cur_sum;
        if (cur_sum == -1) {
            exit(1);
        }
        cout << "! " << cur_sum << endl;
        cout.flush();
    }
}