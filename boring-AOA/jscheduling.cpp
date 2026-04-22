#include <bits/stdc++.h>
using namespace std;

struct Job {
    char id;
    int profit;
    int deadline;
};


bool cmp(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {

    int n;
    cin >> n;

    vector<Job>v(n);
    cout << "Enter the jobs\n";

    for(int i =0; i < n; ++i) {
        cin >> v[i].id >> v[i].profit >> v[i].deadline;
    }

    // Sort based off on profit.
    sort(v.begin(), v.end(), cmp);

    int md = 0;
    for(auto x : v) {
        md = max(md, x.deadline);
    }

    vector<char>slots(md + 1, '-');
    int totalProfit = 0;

    for(auto job : v) {
        for(int j = job.deadline; j > 0; j--) {
            if(slots[j] == '-') {
                slots[j] = job.id;
                totalProfit += job.profit;
                break;
            }
        }
    }

    cout << "\nScheduled Jobs:\n";
    for (int i = 1; i <= md; i++) {
        if (slots[i] != '-')
            cout << "Time " << i + 1 << ": Job " << slots[i] << "\n";
    }

    cout << "\nTotal Profit: " << totalProfit << "\n";

    return 0;
}