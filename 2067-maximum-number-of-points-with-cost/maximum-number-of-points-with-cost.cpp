class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        vector<vector<long long> > dp(points.size(), vector<long long>(points[0].size(), 0));

        for ( int j=0; j<points[0].size(); j++ ) dp[0][j] = points[0][j];

        for ( int i=1; i<points.size(); i++ )
        {
            long long mx = 0;

            for ( int j=0; j<points[0].size(); j++ )
            {
                mx = max( mx - 1, dp[i - 1][j] );
                dp[i][j] = max(dp[i][j], mx + points[i][j]);
            }

            mx = 0;

            for ( int j=points[0].size() - 1; j>=0; j-- )
            {
                mx = max( mx - 1, dp[i - 1][j] );
                dp[i][j] = max(dp[i][j], mx + points[i][j]);
            }
        }

        return ( *max_element( dp.back().begin(), dp.back().end() ) );
    }
};