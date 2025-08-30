#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int palindromicsum(int arr[], int len) {
    int ans=0;
    for (int i=0; i<len; i++) {
        ans += min(arr[i], arr[len-i-1]);
    }
    return ans;
}

bool is_palindrome(vector<int> n, int len) {
    for (int i=0; 2*i+1<=len; i++) {
        if (n[i] != n[len-i-1]) {
            return false;
        }
    }
    return true;
}

bool solve(int arr[], int n, int k) {
    // n is len of sarr
    if (k==1) {
        return true;
    }
    int sarr[n];
    for (int i=0; i<n; i++) {
        sarr[i]=arr[i];
    }
    sort(sarr, sarr+n);
    int ksmallest=sarr[k-1];
    vector<int> smallest;
    for (int i=0; i<n; i++) {
        if (arr[i] < ksmallest) {
            smallest.push_back(arr[i]);
        }
    }
    int l=smallest.size();
    if (!is_palindrome(smallest, l)) {
        return false;
    }
    int nums[l+1];
    for (int i=0; i<=l; i++) {
        nums[i]=0;
    }
    int index=-1;
    for (int i=0; i<n; i++) {
        if (arr[i] == ksmallest) {
            nums[index+1]++;
        }
        if (index != l-1) {
            if (arr[i] == smallest[index+1]) {
                index++;
            }
        }
    }
    // for (int i=0; i<=l; i++) {
    //     cout << nums[i] << " ";
    // }
    // cout << endl;
    // cout << l << " " << palindromicsum(nums, l+1) << endl;
    return (l+palindromicsum(nums, l+1) >= k-1);
}

int main() {
    int t;
    int n, k;
    int ksmallest;
    bool sol;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n >> k;
        int a[n];
        for (int j=0; j<n; j++) {
            cin >> a[j];
        }
        sol=solve(a, n, k);
        if (sol) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        if (i != t-1) {
            cout << endl;
        }
    }
    return 0;
}
