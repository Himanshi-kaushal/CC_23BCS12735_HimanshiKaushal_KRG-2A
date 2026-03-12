#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<long long, long long> > tasks;

    for (int i = 0; i < n; i++) {
        long long a, d;
        cin >> a >> d;
        tasks.push_back({a, d});
    }

    sort(tasks.begin(), tasks.end());

    long long time = 0;
    long long reward = 0;

    for (int i = 0; i < n; i++) {
        time += tasks[i].first;
        reward += tasks[i].second - time;
    }

    cout << reward << endl;

    return 0;
}
