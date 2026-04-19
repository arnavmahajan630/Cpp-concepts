#include <bits/stdc++.h>
using namespace std;

int main() {

    int n = 10;
    vector<int>v(n);
    vector<bool>viz(n, false);

    int head;
    cout << "Enter the inital Head Position (0 - 199): " << endl;
    cin >> head;

    cout << "Enter the 10 Disk requests - \n" << endl;
    for(auto &x : v)cin >> x;

    int totalSeek = 0;
    int cur = head;

    cout << "\nSSTF Disk Scheduling\n";
    cout << "---------------------------------------------------\n";
    cout << "From\tTo\tSeek\n";
    cout << "---------------------------------------------------\n";

    // for n times we need to count for each element the closest one for the current head

    for(int i = 0; i < n; ++i) {
        int idx = -1;
        int minDist = INT_MAX;

        // find the closest to current head

        for(int j = 0; j < n; ++j) {
            if(!viz[j]) {
                int dist = abs(cur - v[j]);
                if(dist < minDist) {
                    minDist = dist;
                    idx = j;
                }
            }
        }

        // work with the minimum found request

        viz[idx] = true;
        cout << cur << "\t" << v[idx] << "\t" << minDist << endl;
        totalSeek += minDist;
        cur = v[idx];
    }

    cout << "----------------------------------------------------\n";
    cout << "Total Seek Time: " << totalSeek << endl;

    return 0;
}
