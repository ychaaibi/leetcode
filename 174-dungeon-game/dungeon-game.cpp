class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int dp[201][201];
        int m = dungeon.size(), n = dungeon[0].size();
        
        dp[m - 1][n - 1] = dungeon[m - 1][n - 1];
        for (int i=n - 2; i>= 0; i--)
        {
            dp[m - 1][i] = dungeon[m - 1][i] + dp[m - 1][i + 1];
            if (dungeon[m - 1][i] < 0)
                dp[m - 1][i] = min(dungeon[m - 1][i], dp[m - 1][i]);
        }
        for (int i=m - 2; i>= 0; i--)
        {
            dp[i][n - 1] = dungeon[i][n - 1] + dp[i + 1][n - 1];
            if (dungeon[i][n - 1] < 0)
                dp[i][n - 1] = min(dungeon[i][n - 1], dp[i][n - 1]);
        }
        for (int i=m - 2; i>= 0; i--)
        {
            for (int j=n - 2; j>= 0; j--)
            {
                dp[i][j] = dungeon[i][j] + max(dp[i + 1][j], dp[i][j + 1]), dp[i][j];
                if (dungeon[i][j] < 0)
                    dp[i][j] = min(dungeon[i][j], dp[i][j]);
                if (dp[i][j] > 0)
                    dp[i][j] = 0;
            }
        }
        return (dp[0][0] < 0 ? abs(dp[0][0]) + 1 : 1);
    }
};