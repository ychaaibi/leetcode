class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int>         num_edges(n, 0);
        
        for ( int i=0; i<edges.size(); i++ )
        {
            graph[edges[i][0]].push_back( edges[i][1] );
            graph[edges[i][1]].push_back( edges[i][0] );
            num_edges[edges[i][0]]++, num_edges[edges[i][1]]++;
        }
        
        queue<int>      q;
        int             size = n;
        
        for ( int i=0; i<n; i++ )
            if ( num_edges[i] <= 1 )
                q.push( i );
                
        while ( size > 2 )
        {
            int s = q.size();
            
            size -= s;
            
            while (s--)
            {
                int curr = q.front();
                
                q.pop();
                
                for ( int i=0; i<graph[curr].size(); i++ )
                {
                    num_edges[graph[curr][i]]--;
                    
                    if ( num_edges[graph[curr][i]] == 1 )
                    {
                        num_edges[graph[curr][i]]--;
                        q.push( graph[curr][i] );
                    }
                }
            }
        }
        
        vector<int> ans;
        
        while ( !q.empty() )
        {
            ans.push_back( q.front() );
            q.pop();
        }
        return ( ans );
    }
};