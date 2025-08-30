#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
using namespace std;

int main() {
    int t;
    int l;
    string s;
    string outstr;
    string temp;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> s;
        outstr="";
        l=s.size();
        for (int j=0; j<l; j++) {
            if (s[j]=='T') {
                outstr.append("T");
            }
        }
        for (int j=0; j<l; j++) {
            if (s[j]!='T') {
                outstr.append(1,s[j]);
            }
        }
        cout << outstr;
        // logic
        if (i != t-1) {
            cout << endl;
        }
    }
    return 0;
}
