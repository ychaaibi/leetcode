class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> ans( grid.size() - 2, vector<int>(grid[0].size() - 2) );

        for ( int i=0; i<grid.size() - 2; i++ )
        {
            for ( int j=0; j<grid[0].size() - 2; j++ )
            {
                int mx = grid[i][j];

                for ( int k=0; k<3; k++ )
                    for ( int l=0; l<3; l++ )
                        mx = max(mx, grid[i + k][j + l]);
                ans[i][j] = mx;
            }
        }

        return ( ans );
    }
};