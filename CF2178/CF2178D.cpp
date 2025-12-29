#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <cmath>
#include <map>
#include <string>
#include <numeric>
using namespace std;

bool ispossible(int m, int n) {
    return (2*m <= n);
}

int main() {
    int t, n, m;
    vector<int> attackers;
    vector<int> defenders;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n >> m;
        attackers.clear();
        defenders.clear();
        int arr[n];
        map<int, int> ind_map;
        for (int j=0; j<n; j++) {
            cin >> arr[j];
            ind_map[arr[j]] = j;
        }
        if (!ispossible(m,n)) {
            cout << -1;
            if (i != t-1) {
                cout << endl;
            }
            continue;
        }
        sort(arr, arr+n);
        reverse(arr, arr+n);
        if (m == 0) {
            int cur_val = arr[0];
            int max_j=0;
            for (int j=1; j<n; j++) {
                attackers.push_back(j);
                defenders.push_back(0);
                cur_val -= arr[j];
                // cout << cur_val << " ";
                if (cur_val <= 0) {
                    max_j = j;
                    break;
                }
            }
            if (max_j == 0) {
                cout << -1;
            }
            else {
                for (int j=max_j+1; j<n; j++) {
                    // cout << cur_val << " ";
                    attackers.push_back(j);
                    defenders.push_back(j-1);
                }
                reverse(attackers.begin(), attackers.end());
                reverse(defenders.begin(), defenders.end());
                cout << attackers.size() << endl;
                for (int j=0; j<attackers.size(); j++) {
                    cout << ind_map[arr[attackers[j]]] + 1 << " " << ind_map[arr[defenders[j]]] + 1;
                    if (j != attackers.size()-1) {
                        cout << endl;
                    }
                }
            }
            if (i != t-1) {
                cout << endl;
            }
            // m=0 is special case
            continue;
        }
        int survivors[m];
        int meatshields[m];
        for (int j=0; j<m; j++) {
            survivors[j] = arr[j];
            meatshields[j] = arr[j+m];
        }
        // From 2m to n, we have each of them attack the meatshield with greatest health (make sure they survive)
        for (int j=2*m; j<n; j++) {
            attackers.push_back(j);
            defenders.push_back(j-m);
        }
        reverse(attackers.begin(), attackers.end());
        reverse(defenders.begin(), defenders.end());
        // Then, each survivor attacks a meatshield
        for (int j=0; j<m; j++) {
            attackers.push_back(j);
            defenders.push_back(j+m);
        }
        cout << attackers.size() << endl;
        for (int j=0; j<attackers.size(); j++) {
            cout << ind_map[arr[attackers[j]]] + 1 << " " << ind_map[arr[defenders[j]]] + 1;
            if (j != attackers.size()-1) {
                cout << endl;
            }
        }
        if (i != t-1) {
            cout << endl;
        }
    }
}