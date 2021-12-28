class Solution {
public:
    int uniquePaths(int m, int n) {
        // m x n memo
        vector<vector<int> > memo(m,vector<int>(n, 0));
        //bottom up approach
        for (size_t r = 0; r < m; ++r) {
            for (size_t c = 0; c < n; ++c) {
                if (r == 0 || c == 0) {
                    memo[r][c] = 1;
                } else {
                    memo[r][c] = memo[r-1][c] + memo[r][c-1];
                }
            } //for c
        } //for r
        return memo[m-1][n-1];
    }
};
