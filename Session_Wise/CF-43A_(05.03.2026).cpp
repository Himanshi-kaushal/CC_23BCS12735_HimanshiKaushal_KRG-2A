#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    unordered_map<string, int> scores;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        scores[s]++;
    }
    int best = 0;
    string ans = "";
    for (auto sc : scores)
    {
        if (sc.second > best)
        {
            best = sc.second;
            ans = sc.first;
        }
    }
    cout << ans << endl;
    return 0;
}
