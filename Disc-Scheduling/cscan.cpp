#include <bits/stdc++.h>
using namespace std;

/*
CSCAN Disk Scheduling
- Move in one direction only
- After reaching end, jump to start and continue
*/

int main() {
    int n = 10;
    vector<int> req(n);

    int head;
    cout << "Enter initial head position (0-199): ";
    cin >> head;

    cout << "Enter " << n << " disk requests:\n";
    for (int i = 0; i < n; i++) {
        cin >> req[i];
    }

    vector<int> left, right;

    for (int i = 0; i < n; i++) {
        if (req[i] < head)
            left.push_back(req[i]);
        else
            right.push_back(req[i]);
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int current = head;
    int totalSeek = 0;

    cout << "\nCSCAN Disk Scheduling\n";
    cout << "---------------------------------------------\n";
    cout << "From\tTo\tSeek\n";
    cout << "---------------------------------------------\n";

    // Step 1: Move right
    for (int i = 0; i < right.size(); i++) {
        int dist = abs(current - right[i]);
        cout << current << "\t" << right[i] << "\t" << dist << "\n";
        totalSeek += dist;
        current = right[i];
    }

    // Step 2: Go to end (199)
    int dist = abs(current - 199);
    cout << current << "\t" << 199 << "\t" << dist << "\n";
    totalSeek += dist;
    current = 199;

    // Step 3: Jump to 0
    dist = abs(current - 0);
    cout << current << "\t" << 0 << "\t" << dist << " (jump)\n";
    totalSeek += dist;
    current = 0;

    // Step 4: Move right again (serve left list)
    for (int i = 0; i < left.size(); i++) {
        dist = abs(current - left[i]);
        cout << current << "\t" << left[i] << "\t" << dist << "\n";
        totalSeek += dist;
        current = left[i];
    }

    cout << "---------------------------------------------\n";
    cout << "Total Seek Time: " << totalSeek << "\n";

    return 0;
}