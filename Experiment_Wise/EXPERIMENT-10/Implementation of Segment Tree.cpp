#include <iostream>
using namespace std;

class SegmentTree {
    int *tree;
    int n;

public:
    SegmentTree(int arr[], int size) {
        n = size;
        tree = new int[4 * n];
        build(arr, 0, 0, n - 1);
    }

    // Build the segment tree
    void build(int arr[], int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    // Range sum query
    int query(int node, int start, int end, int l, int r) {
        // No overlap
        if (r < start || end < l)
            return 0;

        // Complete overlap
        if (l <= start && end <= r)
            return tree[node];

        // Partial overlap
        int mid = (start + end) / 2;
        int leftSum = query(2 * node + 1, start, mid, l, r);
        int rightSum = query(2 * node + 2, mid + 1, end, l, r);

        return leftSum + rightSum;
    }

    // Point update
    void update(int node, int start, int end, int idx, int value) {
        if (start == end) {
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;

            if (idx <= mid)
                update(2 * node + 1, start, mid, idx, value);
            else
                update(2 * node + 2, mid + 1, end, idx, value);

            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }
};
