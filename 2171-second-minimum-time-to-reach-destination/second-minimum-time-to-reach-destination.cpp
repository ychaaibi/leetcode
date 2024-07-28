class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> graph( n );

        for ( int i=0; i<edges.size(); i++ )
            graph[edges[i][0] - 1].push_back( edges[i][1] - 1 ), graph[edges[i][1] - 1].push_back( edges[i][0] - 1 );

        queue<pair<int,int>>    pq;

        vector<unordered_set<int>>  parent( n );
        vector<int>                 path( n, INT_MAX );

        path[0] = 1;

        pq.push( make_pair(0, 1) );

        while ( !pq.empty() )
        {
            auto nd_count = pq.front().second, nd = pq.front().first;

            pq.pop();

            for ( auto neigh : graph[nd] )
            {
                if ( path[neigh] == INT_MAX )
                {
                    pq.push( make_pair(neigh, nd_count + 1) );
                    path[neigh] = nd_count + 1;
                }
                
                // cout << path[neigh] << " " << nd_count + 1 << endl;
                if ( nd_count + 1 == path[neigh] )
                    parent[neigh].insert( nd );
            }
        }

        vector<int>    is_in_sp( n, -1 );
        queue<pair<int,int>>      q;
        
        is_in_sp[n - 1] = 1;

        q.push( make_pair( n - 1, 1 ) );

        while ( !q.empty() )
        {
            auto curr = q.front().first, nd_c = q.front().second;

            q.pop();

            for ( auto p : parent[curr] )
            {
                // cout << "here " << curr << ", " << p << endl;
                if ( is_in_sp[ p ] != -1 )
                    continue ;

                is_in_sp[ p ] = nd_c + 1;
                q.push( make_pair(p, nd_c + 1) );
            }
        }

        vector<bool>    vis( n, false );

        pq.push( make_pair(0, 1) );
        vis[0] = true;

        int ans = INT_MAX;

        while ( !pq.empty() )
        {
            auto nd_count = pq.front().second, nd = pq.front().first;

            pq.pop();

            for ( auto neigh : graph[nd] )
            {
                if ( is_in_sp[neigh] != -1 )
                {
                    if ( nd_count + is_in_sp[neigh] > is_in_sp[0] )
                        ans = min(ans, nd_count + is_in_sp[neigh]);
                }

                if ( vis[neigh] )
                    continue ;

                vis[neigh] = true;

                pq.push( make_pair(neigh, nd_count + 1) );
            } 
        }

        int _ans = 0;

        while ( --ans )
        {
            if ( ( _ans / change ) % 2  )
                _ans = _ans + ( change - (_ans % change) );

            _ans += time;
        }

        return ( _ans );
    }
};