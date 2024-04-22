class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>   unpassed;
        int                     dirs[2] = {-1, 1};
        
        for ( int i=0; i<deadends.size(); i++ )
            unpassed.insert(deadends[i]);

        queue<pair<int,string>>  q;
        
        if ( unpassed.find("0000") != unpassed.end())
            return (-1);
        
        unpassed.insert( "0000" );
        q.push( make_pair(0,"0000") );
        
        
        while ( !q.empty() )
        {
            auto [value, curr] = q.front();
            
            if ( curr == target )
                return ( value );
                
            q.pop();


            for ( int i=0; i<4; i++ )
            {   
                for ( int k=0; k<2; k++ )
                {
                    char n = curr[i] + dirs[k];
                    
                    if ( n < '0' )
                        n = '9';
                    else if ( n > '9' )
                        n = '0';
                    
                    if ( curr[i] == n )
                        continue ;
                    
                    char val = curr[i];
                    
                    curr[i] = n;
                    
                    if ( unpassed.find( curr ) != unpassed.end() )
                    {
                        curr[i] = val;
                        continue ;
                    }
                    
                    int _val = min(max(curr[i], val) - min(curr[i], val), min(curr[i], val) + 10 - max(val, curr[i]) );
                    
                    unpassed.insert(curr);
                    q.push( make_pair( _val + value, curr ) );
                    curr[i] = val;
                }
            }
        }
        return (-1);
    }
};