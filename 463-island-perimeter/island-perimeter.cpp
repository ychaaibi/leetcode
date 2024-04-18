class Solution {
public:
    int get_count( vector<vector<int>>& grid, int i, int j )
    {
        return ( ( i - 1 < 0 or !grid[i - 1][j] )             +
                 ( i + 1 >= grid.size() or !grid[i + 1][j] )  + 
                 ( j - 1 < 0 or !grid[i][j - 1] )             +
                 ( j + 1 >= grid[0].size() or !grid[i][j + 1]) );
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int             ans = 0;
        
        for ( int i=0; i<grid.size(); i++ )
            for ( int j=0; j<grid[0].size(); j++ )
                if ( grid[i][j] )
                    ans += get_count( grid, i, j );
        
        return ( ans );
    }
};