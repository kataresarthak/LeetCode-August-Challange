class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        const int n = points.size(), m = points[0].size();
        long long dp[m], lmax[m], rmax[m];
        for (int i = 0; i < m; i++)
            dp[i] = points[0][i];
        for (int i = 1; i < n; i++) {
            lmax[0] = dp[0];
            for (int i = 1; i < m; i++)
                lmax[i] = max(lmax[i-1], dp[i] + i);
            rmax[m-1] = dp[m-1] - m + 1;
            for (int i = m-2; i > -1; i--)
                rmax[i] = max(rmax[i+1], dp[i] - i);
            for (int j = 0; j < m; j++)
                dp[j] = points[i][j] + max(lmax[j] - j, rmax[j] + j);
        }
        return *max_element(dp, dp + m);
    }
};