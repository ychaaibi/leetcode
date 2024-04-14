class Solution {
public:
    vector<int>             graph_color;
    vector<bool>            is_primes;
    vector<int>             primes;
    vector<vector<int> >    divs;
    vector<int>             divs_vis;
    map<int,vector<int> >   graph;

    void            get_primes()
    {
        for ( int i=2; i<is_primes.size(); i++ )
        {
            if ( !is_primes[i] ) continue ;
            
            for ( int k=2; i * k < is_primes.size(); k++ ) is_primes[ i * k ] = false;
            primes.push_back( i );
        }
    }

    void            construct_graph( )
    {
        for ( int i=0; i<divs.size(); i++ )
        {
            for ( int j=0; j<divs[i].size(); j++ )
            {
                if ( graph.find(divs[i][j]) == graph.end() )
                    graph[divs[i][j]] = vector<int>();
                graph[divs[i][j]].push_back(i);
            }
        }

    }

    void            construct_divs( int num, int node)
    {
        for ( int i=0; i<primes.size() and primes[i] * primes[i] <= num; i++ )
        {
            if ( num % primes[i] ) continue ;

            divs[node].push_back( primes[i] );

            while ( num % primes[i] == 0 )
                num /= primes[i];
        }

        if ( num != 1 )
            divs[node].push_back(num);
    }

    void            construct_divs_nodes( vector<int>& nums )
    {
        for ( int i=0; i<nums.size(); i++ )
            construct_divs( nums[i], i );
    }

    void            bfs( int node, int color )
    {
        queue<int>  q;

        graph_color[node] = color;
        q.push( node );

        while ( !q.empty() )
        {
            int curr = q.front();

            q.pop();

            for ( int i=0; i<divs[curr].size(); i++ )
            {
                if ( divs_vis[divs[curr][i]]) continue ;
                divs_vis[divs[curr][i]] = true;
                for ( int j=0; j<graph[divs[curr][i]].size(); j++ )
                {   
                    if ( graph_color[graph[divs[curr][i]][j]] != -1 )
                        continue ;

                    graph_color[graph[divs[curr][i]][j]] = color;

                    q.push( graph[divs[curr][i]][j] );
                }
            }
        }
    }

    bool    gcdSort(vector<int>& nums) {
        graph_color.resize( nums.size(), -1);
        divs.resize( nums.size() );
        is_primes.resize( 1001, true );
        divs_vis.resize(1e5 + 1, false );

        get_primes();
        construct_divs_nodes( nums );
        construct_graph();

        for ( int i=0; i<graph_color.size(); i++ )
        {
            if ( graph_color[i] != -1 ) continue ;

            bfs( i, i );
        }
    
        vector<pair<int,int> >  sorted(nums.size(), pair<int,int>() );

        for ( int i=0; i<nums.size(); i++ )
            sorted[i] = make_pair(nums[i], i);

        sort(sorted.begin(), sorted.end());

        for ( int i=0; i<sorted.size(); i++ )
        {
            if ( graph_color[sorted[i].second] != graph_color[i] )
                return ( false ); 
        }

        return ( true );
    }
};