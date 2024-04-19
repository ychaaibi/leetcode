class Solution {
public:
    int dirs[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        
        for ( int i=0; i<grid.size(); i++ )
        {
            for ( int j=0; j<grid[0].size(); j++ )
            {
                if ( grid[i][j] == '0' )
                    continue ;
                
                queue<pair<int,int>>  q;                
                q.push(make_pair(i, j));
                
                while ( !q.empty() )
                {
                    auto c = q.front();
                    
                    q.pop();
                    
                    for ( int d = 0; d<4; d++ )
                    {
                        auto _c = make_pair( c.first + dirs[d][0], c.second + dirs[d][1] );
                        
                        if ( _c.first >= grid.size() or _c.first < 0 or _c.second >= grid[0].size() or _c.second < 0 )
                            continue ;
                        if ( grid[_c.first][_c.second] == '0' )
                            continue ;
                        q.push( _c );
                        grid[_c.first][_c.second] = '0';
                    }
                }
                ans++;
            }
        }
        return (ans);
    }
};