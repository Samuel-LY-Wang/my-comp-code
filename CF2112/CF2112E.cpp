#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
using namespace std;

int recurse(int arr[], int n) {
    int curmax=(n+1)/2;
    int p;
    curmax=min(curmax, arr[n-2]+1);
    for (int i=3; i*i<=n; i+=2) {
        if (n%i==0) {
            curmax=min(curmax, arr[i]+arr[n/i]-1);
        }
    }
    return curmax;
}

// NEW SOL:
// DP based on all possibilities
// knowing what prime factors {p,q,r} exist, do the following:
// f(n)=min(f(n-2)+1, f(n/p)+f(p)-1, f(n/q)+f(q)-1, f(n/r)+f(r)-1)

// SAVE TIME MEASURES:
// pre-compile list of primes (only need to go to sqrt(n) for obv reasons)
// pre-compute f for all n and only perform a simple lookup for every testcase

int main() {
    // int primes[125]={3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701};
    int t;
    int answers[500000]={0};
    answers[1]=1;
    for (int i=3; i<500000; i += 2) {
        answers[i]=recurse(answers, i);
        // cout << answers[i] << " ";
    }
    cin >> t;
    int m;
    for (int i=0; i<t; i++) {
        cin >> m;
        if (m%2==0) {
            cout << -1;
        }
        else {
            cout << answers[m];
        }
        if (i != t-1) {
            cout << endl;
        }
    }
}
