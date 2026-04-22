#include <bits/stdc++.h>
using namespace std;


void insertionSort(vector<int>&v, int n) {

    for(int i= 1; i <= n-1; ++i) {
        int cur = v[i]; // the current element
        int prev = i-1; // immediate previous element postion

        while(prev >= 0 and v[prev] > cur) {
            v[prev + 1] = v[prev]; // the current element comes back
            prev--; // poijnter moves ahead for further checking
        }
        // prev will be 1 before the correct position
        v[prev + 1] = cur; // place the correct elment

    }
}

int main() {

    int n;
    cin >> n;
    vector<int>v(n);

    for(auto & x : v)cin >> x;
    insertionSort(v, n);
    for(auto x : v)cout << x << " ";
    return 0;
}