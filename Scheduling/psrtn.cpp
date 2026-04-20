#include <bits/stdc++.h>
using namespace std;

struct Process {
    int id, at, bt, rt, ct, tat, wt;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);

    for (int i = 0; i < n; i++) {
        cout << "Process [P" << i << "] - Enter Arrival Time & Burst Time: ";
        cin >> p[i].at >> p[i].bt;
        p[i].id = i;
        p[i].rt = p[i].bt;
    }

    int completed = 0, t = 0;
    int prev = -1; // track previous running process

    cout << "\n--- Execution Log ---\n";

    while (completed < n) {
        int idx = -1;
        int minRT = INT_MAX;

        // find process with shortest remaining time
        for (int i = 0; i < n; i++) {
            if (p[i].at <= t && p[i].rt > 0) {
                if (p[i].rt < minRT) {
                    minRT = p[i].rt;
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            t++;
            continue;
        }

        // if process changes → log event
        if (prev != idx) {
            if (prev != -1 && p[prev].rt > 0) {
                cout << "[Time " << t << "] P" << prev
                     << " preempted by P" << idx << "\n";
            } else {
                cout << "[Time " << t << "] P" << idx
                     << " starts execution\n";
            }
        }

        prev = idx;

        // execute for 1 unit
        p[idx].rt--;
        t++;

        // if finished
        if (p[idx].rt == 0) {
            completed++;
            p[idx].ct = t;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;

            cout << "[Time " << t << "] P" << idx << " finished\n";
            prev = -1; // reset so next process logs "start"
        }
    }

    // Final Table
    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";

    for (auto &pr : p) {
        cout << "P" << pr.id << "\t"
             << pr.at << "\t"
             << pr.bt << "\t"
             << pr.ct << "\t"
             << pr.tat << "\t"
             << pr.wt << "\n";
    }

    return 0;
}