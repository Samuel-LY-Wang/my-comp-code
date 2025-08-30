#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
using namespace std;

int numruns(string beaker) {
    size_t l=beaker.length(); 
    int numruns=1;
    for (int i=1; i<l; i++) {
        if (beaker[i] != beaker[i-1]) {
            numruns++;
        }
    }
    return numruns;
}

int main() {
    freopen("testtube.in", "r", stdin);
    freopen("testtube.out", "w", stdout);
    int t;
    cin >> t;
    int n,p;
    for (int i=0; i<t; i++) {
        cin >> n >> p;
        string f,s;
        cin >> f >> s;
        int runs1 = numruns(f), runs2 = numruns(s);
        // cout << "[" << runs1 << ", " << runs2 << "]" << endl;
        int end1=int(f[n-1])-96, end2=int(s[n-1])-96;
        int runs3=0;
        int end3=3-end2;
        // TODO: replace 1 2D vec with 2 1D vectors
        vector<int> from, to;
        while (true) {
            if (runs1 == 1) {
                if (runs2 == 1 && runs3 == 0) {
                    break;
                }
                else if (runs2 == 0 && runs3 > 0) {
                    from.push_back(3);
                    to.push_back(2);
                    runs2++;
                    runs3--;
                    end2=end3;
                }
                else if (runs2 == 1) {
                    if (end3 == end1) {
                        from.push_back(3);
                        to.push_back(1);
                        break;
                    }
                    else {
                        from.push_back(3);
                        to.push_back(2);
                        break;
                    }
                }
                else if (end1==end3 && runs3 > 0) {
                    from.push_back(3);
                    to.push_back(1);
                    runs3=0;
                }
                else if (end1 == end3) {
                    end3 = 3-end3;
                }
                else if (end2 == end1) {
                    from.push_back(2);
                    to.push_back(1);
                    runs2--;
                    end2 = 3-end2;
                }
                else if (end2 == end3) {
                    from.push_back(2);
                    to.push_back(3);
                    runs2--;
                    end2 = 3-end2;
                }
            }
            else {
                if (end1 == end2) {
                    from.push_back(1);
                    to.push_back(2);
                    end1 = 3-end1;
                    runs1--;
                }
                else {
                    from.push_back(1);
                    to.push_back(3);
                    end3=end1;
                    end1=3-end1;
                    runs1--;
                    runs3=1;
                }
            }
        }
        int m=from.size();
        cout << m;
        if (p == 1 && i != t-1) {
            cout << endl;
        }
        if (p > 1) {
            cout << endl;
            for (int j=0; j<m; j++) {
                cout << from[j] << " " << to[j];
                if (j<m-1 || i<t-1) {
                    cout << endl;
                }
            }
        }
    }
}