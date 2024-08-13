class Solution {
public:
    bool isIsomorphic(string s, string v) {
    
    
    unordered_map<char,char> mp_ch;
    unordered_map<char,char> mp_int;
    
    for ( int i=0; i<v.length(); i++ )
    {
        if ( ( mp_ch.find(s[i]) == mp_ch.end() ) != ( mp_int.find( v[i] ) == mp_int.end() ) )
        {
            cout << "NO" << endl;
            return (false);
        }
        
        if ( mp_ch.find(s[i]) == mp_ch.end() )
        {
            mp_ch[s[i]] = v[i], mp_int[v[i]] = s[i];
            continue ;
        }
        
        if ( mp_ch[s[i]] != v[i] or mp_int[v[i]] != s[i] )
        {
            cout << "NO" << endl;
            return (false);
        }
    }
    return ( true );
    }
};