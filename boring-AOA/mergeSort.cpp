#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>&v, int s, int e) {
    int i = s;
    int mid = (s + e)/2;
    int j = mid + 1;


    vector<int>temp;
    while(i <= mid and j <= e) {
        if(v[i] < v[j])temp.push_back(v[i++]);
        else temp.push_back(v[j++]);
    }

    while(i <= mid)temp.push_back(v[i++]);
    while(j <= e)temp.push_back(v[j++]);

    int k = 0;
    for(int idx = s; idx <= e; ++idx) {
        v[idx] = temp[k++];
    }
}


void mergeSort(vector<int>&v, int s, int e) {
    if(s >= e)return;

    int mid = (s + e)/2;

    mergeSort(v, s, mid);
    mergeSort(v, mid + 1, e);
    return merge(v, s, e);
}

int main() {

    cout << "Enter the Size of the arrays to Sort: ";
    int n;
    cin >> n;

    cout << "\nEnter the " << n << " elements to sort space seperated: ";
    vector<int>v(n);
    for(auto & x : v)cin >> x;

    int s = 0;
    int e = v.size() -1;

    mergeSort(v, s, e);

    cout << "The merge Sorted Array is as Follows: ";
    for(auto x : v)cout << x << " ";
    cout << endl;
    return 0;
}