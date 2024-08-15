class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int>  d;

        d[5] = d[10] = d[20] = 0;

        for ( int i=0; i<bills.size(); i++ )
        {
            if ( bills[i] == 10 )
            {
                if ( !d[5] )
                    return ( false );
                d[5]--;
            }
            else if ( bills[i] == 20 )
            {
                if ( d[10] and d[5] )
                    d[10]--, d[5]--;
                else if ( d[5] >= 3 )
                    d[5] -= 3;
                else
                    return ( false );
            }
            
            d[bills[i]]++;
        }

        return ( true );
    }
};