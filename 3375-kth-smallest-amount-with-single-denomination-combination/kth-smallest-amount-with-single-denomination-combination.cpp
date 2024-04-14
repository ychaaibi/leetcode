#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int ans = 0;

    long long get_num_divs( const vector<int>& coins, long long val, int count, int curr, long long lc )
    {   
        if ( curr == coins.size() )
        {
            if ( count == 0 )
                return (0);
            
            if ( count % 2 )
                return ( val / lc );
            else
                return ( -val / lc );
        }
        
        return get_num_divs( coins, val, count + 1, curr + 1, lcm(lc, coins[curr]) )
                + get_num_divs( coins, val, count, curr + 1, lc);
    }
    
    long long findKthSmallest(vector<int>& coins, int k) {
        
        for ( int i=0; i<coins.size(); i++ )
        {
            long long l = 1, r = k * (long long)coins[i];
            
            while ( l <= r )
            {
                long long md = ( l + r ) / 2;
                long long ans = get_num_divs( coins, md * coins[i], 0, 0, 1);
                
                if ( ans == k )
                    return ( md * coins[i] );
                else if ( ans > k )
                    r = md - 1;
                else
                    l = md + 1;
            }
        }
        
        // Can't be
        return ( -1 );
    }
};