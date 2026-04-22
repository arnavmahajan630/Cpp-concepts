#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value, weight;
};

// Comparator: sort by value/weight ratio descending
bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);

    cout << "Enter value and weight for each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
    }

    int W;
    cout << "Enter knapsack capacity: ";
    cin >> W;

    // Step 1: Sort by ratio
    sort(items.begin(), items.end(), cmp);

    double totalValue = 0.0;

    // Step 2: Fill knapsack
    for (auto &item : items) {

        if (W >= item.weight) {
            // take full item
            totalValue += item.value;
            W -= item.weight;
        } else {
            // take fraction
            totalValue += ((double)item.value / item.weight) * W;
            break;
        }
    }

    cout << "\nMaximum value in knapsack = " << totalValue << "\n";

    return 0;
}