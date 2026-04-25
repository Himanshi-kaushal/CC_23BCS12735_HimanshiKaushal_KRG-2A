#include <iostream>
using namespace std;

const int MAXN = 1000;
int BIT[MAXN];
int N;

void update(int i, int v) {
    while (i <= N) {
        BIT[i] += v;
        i += (i & -i);
    }
}

int prefixSum(int i) {
    int sum = 0;
    while (i > 0) {
        sum += BIT[i];
        i -= (i & -i);
    }
    return sum;
}

int rangeSum(int L, int R) {
    return prefixSum(R) - prefixSum(L - 1);
}

int main() {
    N = 5;

    update(1, 5);
    update(2, 3);
    cout << rangeSum(1, 2) << endl;
    update(5, 10);
    cout << rangeSum(1, 5) << endl;

    return 0;
}
