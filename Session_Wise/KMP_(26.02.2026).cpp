#include <bits/stdc++.h>
using namespace std;

vector<int> buildLPS(const string &pat) {
    int m = (int)pat.size();
    vector<int> lps(m, 0);
    int len = 0;

    for (int i = 1; i < m; ) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) len = lps[len - 1];
            else { lps[i] = 0; i++; }
        }
    }
    return lps;
}

int main() {
    string text = "acbdabchd";
    string pat  = "abc";

    int n = (int)text.size();
    int m = (int)pat.size();

    vector<int> lps = buildLPS(pat);

    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pat[j]) { i++; j++; }

        if (j == m) {
            cout << "pattern found at index " << (i - m) << "\n";
            j = lps[j - 1];
        } else if (i < n && text[i] != pat[j]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
    return 0;
}
