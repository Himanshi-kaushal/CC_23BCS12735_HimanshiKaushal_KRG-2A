#include <iostream>
using namespace std;

struct Pt {
    long long x, y;
};

static inline __int128 cross(const Pt& a, const Pt& b, const Pt& c) {
    return (__int128)(b.x - a.x) * (c.y - a.y) - (__int128)(b.y - a.y) * (c.x - a.x);
}

static inline __int128 area2(Pt* p, int n) {
    __int128 s = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        s += (__int128)p[i].x * p[j].y - (__int128)p[j].x * p[i].y;
    }
    return s;
}

static inline bool inside_strict_convex_ccw(Pt* a, int n, const Pt& q) {
    if (cross(a[0], a[1], q) <= 0) return false;
    if (cross(a[0], a[n - 1], q) >= 0) return false;

    int l = 1, r = n - 1;
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        if (cross(a[0], a[mid], q) > 0) l = mid;
        else r = mid;
    }
    return cross(a[l], a[l + 1], q) > 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    Pt* A = new Pt[n];
    for (int i = 0; i < n; i++) cin >> A[i].x >> A[i].y;

    if (area2(A, n) < 0) {
        for (int i = 0; i < n / 2; i++) {
            Pt tmp = A[i];
            A[i] = A[n - 1 - i];
            A[n - 1 - i] = tmp;
        }
    }

    int m;
    cin >> m;
    Pt* B = new Pt[m];
    for (int i = 0; i < m; i++) cin >> B[i].x >> B[i].y;

    for (int i = 0; i < m; i++) {
        if (!inside_strict_convex_ccw(A, n, B[i])) {
            cout << "NO\n";
            delete[] A;
            delete[] B;
            return 0;
        }
    }

    cout << "YES\n";
    delete[] A;
    delete[] B;
    return 0;
}
