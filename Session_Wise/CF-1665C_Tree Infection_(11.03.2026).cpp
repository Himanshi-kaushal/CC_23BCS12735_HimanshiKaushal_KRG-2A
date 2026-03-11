#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool check(int mid, int k, const vector<int>& groups) {
    long long extra_injections_needed = 0;
    for (int i = 0; i < k; ++i) {
        // Initial injection at second (i+1)
        // Spreading starts at second (i+2)
        // Total time available for this group is 'mid'
        // Time spent spreading = mid - (i + 1)
        int spreading_time = mid - (i + 1);
        int remaining = groups[i] - 1 - max(0, spreading_time);
        
        if (remaining > 0) {
            extra_injections_needed += remaining;
        }
    }
    // We have 'mid' total seconds, but 'k' seconds were 
    // already used for the mandatory initial injections.
    return extra_injections_needed <= (mid - k);
}

void solve() {
    int n;
    cin >> n;
    
    // Step 1: Count children for each vertex to form sibling groups
    map<int, int> counts;
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        counts[p]++;
    }
    
    vector<int> groups;
    for (auto const& [parent, size] : counts) {
        groups.push_back(size);
    }
    // Add the root itself as a group of size 1
    groups.push_back(1);
    
    // Step 2: Sort descending (inject largest groups first)
    sort(groups.rbegin(), groups.rend());
    int k = groups.size();
    
    // Step 3: Binary Search for the minimum time
    int low = k, high = n, ans = n;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(mid, k, groups)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
