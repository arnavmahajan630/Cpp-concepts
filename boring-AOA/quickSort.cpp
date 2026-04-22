#include <bits/stdc++.h>
using namespace std;


int partiion(vector<int>&v, int s, int e) {
    int i = s -1;
    int pivot = v[e];

    for(int j = s; j < e; ++j) { // iterate over all elements
        if(v[j] < pivot) {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[e]);
    return i + 1;
}

void quickSort(vector<int>&v, int s, int e) {
    // base case

    if(s >= e)return;


    // recursive case

    // motive: is to try to place the pivot in it's correct position
    int p = partiion(v, s, e); // returns the correct position of pivot p
    quickSort(v,s,p-1);  // call on left part
    quickSort(v,p+1,e); // call on the right part


}

int main() {

    int n;
    cin >> n;
    vector<int>v(n);

    for(auto & x : v)cin >> x;
    quickSort(v, 0, n-1);

    for(auto x : v)cout << x<< " ";
    return 0;
}