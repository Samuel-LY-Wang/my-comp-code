#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
using namespace std;
#pragma warning(suppress: 4267)

int binsearch(vector<int> nums, int num) {
    // nums must be sorted
    if (num <= nums[0]) {
        return -1;
    }
    else if (num >= nums[nums.size()-1]) {
        return nums.size()-1;
    }
    int high=nums.size()-1;
    int low=0;
    int mid=(high+low)/2;
    while (true) {
        if (num >=nums[mid] && num<nums[mid+1]) {
            return mid;
        }
        else if (num < nums[mid]) {
            high=mid;
            mid=(high+low)/2;
        }
        else {
            low=mid;
            mid=(high+low)/2;
        }
    }
}

int find(vector<int> a, vector<int> b, int n) {
    if (a.size() == 0 || b.size() == 0) {
        return 0;
    }
    // assume a and b are sorted
    int bprefix[b.size()];
    int sum=0;
    for (int i=0; i<b.size(); i++) {
        sum += b[i];
        bprefix[i]=sum;
    }
    sum=0;
    for (int i=0; i<a.size(); i++) {
        int x=a[i];
        int y=n-a[i];
        int xindex=binsearch(b,x);
        int yindex=binsearch(b,y);
        if (b[xindex] == x) {
            sum += x*(x+1)/2;
            sum += (n-x)*(n-x+1)/2;
        }
        if (x >= y) {
            sum += yindex+bprefix[yindex];
            sum += y*(xindex-yindex);
            sum += n*(n-xindex)-(bprefix[b.size()-1]-bprefix[xindex]);
        }
        else {
            sum += xindex+bprefix[xindex];
            sum += (x+1)*(xindex-yindex);
            sum += n*(n-yindex)-(bprefix[b.size()-1]-bprefix[yindex]);
        }
    }
    return sum;
}

int main() {
  int n;
  cin >> n;
  int a[n], b[n];
  int answer=0;
  map<int, vector<int> > as;
  map<int, vector<int> > bs;
  for (int i=0; i<n; i++) {
    cin >> a[i];
    as[a[i]].push_back(i);
  }
  for (int i=0; i<n; i++) {
    cin >> b[i];
    bs[b[i]].push_back(i);
  }
  for (int i=0; i<n; i++) {
    answer += find(as[i], bs[i], n);
  }
  cout << answer;
  // first tackle the queries starting from the beginning
}