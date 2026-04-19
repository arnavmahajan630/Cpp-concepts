#include <bits/stdc++.h>
using namespace std;

/*
SCAN Disk Scheduling (Elevator Algorithm)
- Move in one direction servicing requests
- Go till end (0 or 199), then reverse
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

    string direction;
    cout << "Enter direction (left/right): ";
    cin >> direction;

    vector<int> left, right;

    for (int i = 0; i < n; i++) {
        if (req[i] < head)
            left.push_back(req[i]);
        else
            right.push_back(req[i]);
    }

    sort(left.begin(), left.end());     // ascending
    sort(right.begin(), right.end());   // ascending

    int current = head;
    int totalSeek = 0;

    cout << "\nSCAN Disk Scheduling\n";
    cout << "---------------------------------------------\n";
    cout << "From\tTo\tSeek\n";
    cout << "---------------------------------------------\n";

    if (direction == "right") {
        // move right
        for (int i = 0; i < right.size(); i++) {
            int dist = abs(current - right[i]);
            cout << current << "\t" << right[i] << "\t" << dist << "\n";
            totalSeek += dist;
            current = right[i];
        }

        // go to end (199)
        int dist = abs(current - 199);
        cout << current << "\t" << 199 << "\t" << dist << "\n";
        totalSeek += dist;
        current = 199;

        // reverse → move left
        for (int i = left.size() - 1; i >= 0; i--) {
            dist = abs(current - left[i]);
            cout << current << "\t" << left[i] << "\t" << dist << "\n";
            totalSeek += dist;
            current = left[i];
        }
    }
    else {
        // move left
        for (int i = left.size() - 1; i >= 0; i--) {
            int dist = abs(current - left[i]);
            cout << current << "\t" << left[i] << "\t" << dist << "\n";
            totalSeek += dist;
            current = left[i];
        }

        // go to start (0)
        int dist = abs(current - 0);
        cout << current << "\t" << 0 << "\t" << dist << "\n";
        totalSeek += dist;
        current = 0;

        // reverse → move right
        for (int i = 0; i < right.size(); i++) {
            dist = abs(current - right[i]);
            cout << current << "\t" << right[i] << "\t" << dist << "\n";
            totalSeek += dist;
            current = right[i];
        }
    }

    cout << "---------------------------------------------\n";
    cout << "Total Seek Time: " << totalSeek << "\n";

    return 0;
}