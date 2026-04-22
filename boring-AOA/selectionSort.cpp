#include <bits/stdc++.h>
using namespace std;


void selectionSort(vector<int>&v, int n) {

    for(int i = 0; i <= n-2; ++i) { // last element auto sorted since max
        int cur = v[i]; // get the current element
        int minpos = i;
        for(int j = i; j <= n-1; ++j) { // loop from current position to last to get the minimum element
            if(v[j] < v[minpos])minpos = j;
        }

        // now we have the minimum element and it's positon
        // swap the elements with current

        swap(v[i], v[minpos]);

    }

}

int main() {

    int n;
    cin >> n;
    vector<int>v(n);

    for(auto & x : v)cin >> x;
    selectionSort(v, n);
    for(auto x : v)cout << x << " ";
    return 0;
}