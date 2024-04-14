class Solution {
public:

    bool    is_ans( vector<int>& s_hash, vector<int>& t_hash )
    {
        for ( int i=0; i<s_hash.size(); i++ )
        {
            // cout << char ('A' + i) << " " << s_hash[i] << " t : " << t_hash[i] << endl;
            if ( s_hash[i] < t_hash[i] ) return ( false );
        }
        return ( true );
    }      


    string  minWindow(string s, string t) {
        vector<int> s_hash( 58, 0 );
        vector<int> t_hash( 58, 0 );

        for ( int i=0; i<t.length(); i++ )
            t_hash[ t[i] - 'A' ]++;

        int ans_l = 0, ans_r = s.length() + 1;

        int p1 = 0, p2 = 0;

        while ( p2 < s.length() )
        {
            s_hash[ s[p2] - 'A' ]++;

            if ( is_ans( s_hash, t_hash ) )
            {
                if ( p2 - p1 <= ans_r - ans_l )
                    ans_l = p1, ans_r = p2;

                s_hash[ s[p1] - 'A' ]--;
                s_hash[ s[p2] - 'A' ]--;
                p1++;
            }
            else
                p2++;
        }
        
        if ( ans_r == s.length() + 1 )
            return ( "" );
        
        return ( s.substr( ans_l, ans_r - ans_l +1 ) );
    }
};