#include <bits/stdc++.h>
using namespace std;


int main() {
    int n = 10;
    vector<int>v(n);

    int head;
    cout << "Enter the  inital Head position (0 - 199): ";
    cin >> head;

    cout << "Enter " << n << " disk requests: \n";
    for(auto & x : v)cin >> x;

    int totalSeek = 0;
    int cur = head;


    cout << "\n FCFS DISK SCHEDULING\n";
    cout << "------------------------------------------------\n";
    cout << "From\tTo\tSeek\n";
    cout << "------------------------------------------------\n";

    for(auto x : v) {
        int dist = abs(cur - x);
        cout << cur << "\t" << x << "\t" << dist << "\n";
        totalSeek+=dist;
        cur = x;
    }

    cout << "-------------------------------------------------\n";
    cout << "Total Seek time: " << totalSeek << endl;
    return 0;
}