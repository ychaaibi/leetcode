class Solution {
public:
    int dirs[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
        
    vector<vector<int>> findFarmland(vector<vector<int>>& grid) {
        vector<vector<int>>     ans;
        vector<vector<bool>>    vis(grid.size(), vector<bool>(grid[0].size(), false));
        
        for ( int i=0; i<grid.size(); i++ )
        {
            for ( int j=0; j<grid[0].size(); j++ )
            {
                if ( !grid[i][j] or vis[i][j] )
                    continue ;
                
                vector<int> v(4, -1);
                
                queue<pair<int,int>>  q;                
                q.push(make_pair(i, j));
                
                while ( !q.empty() )
                {
                    auto c = q.front();
                    
                    if ( v[0] == -1
                        and ( c.first == 0 or !grid[c.first - 1][c.second] )
                        and ( c.second == 0 or !grid[c.first][c.second - 1] ) )
                        v[0] = c.first, v[1] = c.second;
                    if ( v[2] == -1
                             and ( c.first == grid.size() - 1 or !grid[c.first + 1][c.second] )
                             and ( c.second == grid[0].size() - 1 or !grid[c.first][c.second + 1] ) )
                        v[2] = c.first, v[3] = c.second;
                        
                    q.pop();
                    
                    for ( int d = 0; d<4; d++ )
                    {
                        auto _c = make_pair( c.first + dirs[d][0], c.second + dirs[d][1] );
                        
                        if ( _c.first >= grid.size() or _c.first < 0 or _c.second >= grid[0].size() or _c.second < 0 )
                            continue ;
                        if ( vis[_c.first][_c.second] or !grid[_c.first][_c.second] )
                            continue ;
                        
                        q.push( _c );
                        vis[_c.first][_c.second] = true;
                    }
                }
                
                ans.push_back( v );
            }
        }
        return (ans);
    }
};
