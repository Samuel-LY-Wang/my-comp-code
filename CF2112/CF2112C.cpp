#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
using namespace std;

int nonstrictbinsearch(int arr[], int len, int num) {
    // finds the unique n such that arr[n]<=num<arr[n+1]
    if (num < arr[0]) {
        return -1;
    }
    if (num >= arr[len-1]) {
        return len-1;
    }
    int low=0;
    int high=len-1;
    int mid;
    while (true) {
        mid=(low+high)/2;
        if (arr[mid] <= num && arr[mid+1] > num) {
            return mid;
        }
        else if (num < arr[mid]) {
            high=mid;
        }
        else {
            low=mid;
        }
    }
}

int gettruemax(int maxes[3], int a, int b) {
    if (a+b == maxes[0] + maxes[1]) {
        return maxes[2];
    }
    if (max(a,b) == maxes[0]) {
        return maxes[1];
    }
    return maxes[0];
}

int main() {
    int t;
    cin >> t;
    int n;
    long long count;
    int minnum, maxnum, raw;
    int maxes[3];
    for (int i=0; i<t; i++) {
        cin >> n;
        count=0;
        int a[n];
        maxes[0]=0; // will be the largest num
        maxes[1]=0; // will be second largest
        maxes[2]=0; // will be third largest
        for (int j=0; j<n; j++) {
            cin >> a[j];
            if (a[j] >= maxes[0]) {
                maxes[2]=maxes[1];
                maxes[1]=maxes[0];
                maxes[0]=a[j];
            }
            else if (a[j] >= maxes[1]) {
                maxes[2]=maxes[1];
                maxes[1]=a[j];
            }
            else if (a[j] >= maxes[2]) {
                maxes[2]=a[j];
            }
        }
        // cout << maxes[2] << " " << maxes[1] << " " << maxes[0] << endl;
        // now we go through each pair
        for (int j=0; j<n-1; j++) {
            for (int k=j+1; k<n; k++) {
                maxnum=a[j]+a[k]-1;
                minnum=max(abs(a[j]-a[k])+1, gettruemax(maxes, a[j], a[k])-a[j]-a[k]+1);
                // cout << minnum << " " << maxnum << endl;
                // cout << nonstrictbinsearch(a, n, maxnum) << " " << nonstrictbinsearch(a, n, minnum-1) << endl;
                raw=nonstrictbinsearch(a, n, maxnum)-nonstrictbinsearch(a, n, minnum-1);
                if (minnum <= a[j] && a[j] <= maxnum) {
                    raw -= 1;
                }
                if (minnum <= a[k] && a[k] <= maxnum) {
                    raw -= 1;
                }
                count += max(raw,0);
                // cout << raw << " ";
                // cout << count << endl;
            }
        }
        cout << count/3;
        if (i != t-1) {
            cout << endl;
        }
    }
}
