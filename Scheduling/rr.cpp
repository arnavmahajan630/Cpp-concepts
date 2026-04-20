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
        cout << "Enter AT and BT for P" << i << ": ";
        cin >> p[i].at >> p[i].bt;
        p[i].id = i;
        p[i].rt = p[i].bt;
    }

    int tq;
    cout << "Enter Time Quantum: ";
    cin >> tq;

    queue<int> q;
    vector<bool> inQueue(n, false);

    int t = 0, completed = 0;

    // initially push processes that arrive at time 0
    for (int i = 0; i < n; i++) {
        if (p[i].at == 0) {
            q.push(i);
            inQueue[i] = true;
        }
    }

    while (completed < n) {

        if (q.empty()) {
            t++; // CPU idle
            for (int i = 0; i < n; i++) {
                if (!inQueue[i] && p[i].at <= t) {
                    q.push(i);
                    inQueue[i] = true;
                }
            }
            continue;
        }

        int idx = q.front();
        q.pop();

        int execTime = min(tq, p[idx].rt);

        p[idx].rt -= execTime;
        t += execTime;

        // add newly arrived processes during execution
        for (int i = 0; i < n; i++) {
            if (!inQueue[i] && p[i].at <= t) {
                q.push(i);
                inQueue[i] = true;
            }
        }

        // if process still has remaining time → reinsert
        if (p[idx].rt > 0) {
            q.push(idx);
        } else {
            completed++;
            p[idx].ct = t;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
        }
    }

    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";

    double avgWT = 0, avgTAT = 0;

    for (auto &pr : p) {
        cout << "P" << pr.id << "\t"
             << pr.at << "\t"
             << pr.bt << "\t"
             << pr.ct << "\t"
             << pr.tat << "\t"
             << pr.wt << "\n";

        avgWT += pr.wt;
        avgTAT += pr.tat;
    }

    cout << "\nAverage WT: " << avgWT / n;
    cout << "\nAverage TAT: " << avgTAT / n;

    return 0;
}