class Solution {
public:
    vector<bool>                        visited;
    vector<vector<int>>                         parent;
    map<pair<int,int>, pair<int,bool>>  vis;

    void    construct_path(int node)
    {
        queue<int>  q;
        
        q.push(node);
        visited[node] = true;

        while ( !q.empty() )
        {
            node = q.front();
            
            q.pop();
            
            for ( int i=0; i<parent[node].size(); i++ )
            {
                int curr = parent[node][i];
                vis[make_pair(min(curr, node), max(curr, node))].second = true;
                
                if (!visited[curr])
                    q.push(curr);
                visited[curr] = true;
            }
        }
    }
    
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<long long>               weight(n, LLONG_MAX);
        vector<vector<pair<int,int>>>   graph(n, vector<pair<int,int>>());
        
        for ( int i=0; i<edges.size(); i++ )
        {
            graph[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]) );
            graph[edges[i][1]].push_back(make_pair(edges[i][0], edges[i][2]) );
            vis[make_pair(min(edges[i][0], edges[i][1]), max(edges[i][1], edges[i][0]))] = make_pair(i, false);
        }
        
        parent.resize(n, vector<int>());
        visited.resize(n, false);
        
        priority_queue<pair<long long,int>, vector<pair<long long,int> >, greater<pair<long long,int>>>  pq;
        
        weight[0] = 0;
        pq.push(make_pair(0, 0));
        
        while ( !pq.empty() )
        {
            auto [ _weight, node ] = pq.top();
            
            pq.pop();
            
            if ( node == n - 1 )
                continue ;
            
            for ( int i=0; i<graph[node].size(); i++ )
            {
                int next_node = graph[node][i].first, next_weight = graph[node][i].second;
                
                if ( weight[next_node] > _weight + next_weight )
                {
                    weight[next_node] = _weight + next_weight;
                    pq.push( make_pair( _weight + next_weight, next_node ) );
                    parent[next_node].clear();
                    parent[next_node].push_back(node);
                }
                else if ( weight[next_node] == _weight + next_weight )
                    parent[next_node].push_back(node);
            }
        }
        
        construct_path( n - 1 );
        
        vector<bool>    ans(edges.size(), false);
        for ( auto& [edge, is] : vis )
            ans[is.first] = is.second;
                          
        return ( ans );
    }
};