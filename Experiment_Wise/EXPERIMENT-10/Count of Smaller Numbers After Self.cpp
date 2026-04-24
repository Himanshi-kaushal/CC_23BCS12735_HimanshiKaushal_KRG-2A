#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        vector<pair<int,int>> arr;

        // store (value, original index)
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        mergeSort(arr, result);
        return result;
    }

private:
    vector<pair<int,int>> mergeSort(vector<pair<int,int>>& arr, vector<int>& result) {
        int n = arr.size();
        if (n <= 1) return arr;

        int mid = n / 2;
        vector<pair<int,int>> left(arr.begin(), arr.begin() + mid);
        vector<pair<int,int>> right(arr.begin() + mid, arr.end());

        left = mergeSort(left, result);
        right = mergeSort(right, result);

        return merge(left, right, result);
    }

    vector<pair<int,int>> merge(vector<pair<int,int>>& left,
                               vector<pair<int,int>>& right,
                               vector<int>& result) {
        vector<pair<int,int>> merged;
        int i = 0, j = 0;
        int rightCount = 0;

        while (i < left.size() && j < right.size()) {
            if (left[i].first > right[j].first) {
                rightCount++;
                merged.push_back(right[j]);
                j++;
            } else {
                result[left[i].second] += rightCount;
                merged.push_back(left[i]);
                i++;
            }
        }

        while (i < left.size()) {
            result[left[i].second] += rightCount;
            merged.push_back(left[i]);
            i++;
        }

        while (j < right.size()) {
            merged.push_back(right[j]);
            j++;
        }

        return merged;
    }
};
