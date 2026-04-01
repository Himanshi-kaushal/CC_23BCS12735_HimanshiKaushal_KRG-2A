class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int ans = 1;

        for (int i = 0; i < n; i++) {
            map<pair<int, int>, int> mp;
            int curMax = 0;

            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0) {
                    dy = 1;   // vertical line
                    dx = 0;
                } 
                else if (dy == 0) {
                    dx = 1;   // horizontal line
                    dy = 0;
                } 
                else {
                    if (dx < 0) {
                        dx = -dx;
                        dy = -dy;
                    }

                    int g = gcd(abs(dx), abs(dy));
                    dx /= g;
                    dy /= g;
                }

                mp[{dy, dx}]++;
                curMax = max(curMax, mp[{dy, dx}]);
            }

            ans = max(ans, curMax + 1); // +1 for anchor point
        }

        return ans;
    }
};
