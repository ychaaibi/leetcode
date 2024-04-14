class Solution {
public:
    bool    valid( string& s1, string& s2 )
    {
        int count = 0;
        
        for ( int i=0; i<s1.length(); i++ )
            count += (s1[i] != s2[i]);
        return ( count == 1 );
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<int>                  q;
        vector<bool>                vis( wordList.size(), false );
        unordered_map<string, int>  hash;
        
        for ( int i=0; i<wordList.size(); i++ )
        {
            hash[wordList[i]] = i;
            if ( valid(beginWord, wordList[i] ) )
            {
                vis[i] = true;
                q.push(i);
            }
        }
        int ans = 0;
        
        while ( !q.empty() )
        {
            int size = q.size();
            
            ans++;
            while ( size-- )
            {
                int curr = q.front();
                
                q.pop();
    
                if ( wordList[curr] == endWord ) return ( ans + 1 );
                for ( int i=0; i<beginWord.length(); i++ )
                {
                    char save = wordList[curr][i];
                    
                    for ( char c='a'; c <= 'z'; c++ )
                    {
                        if ( c == save ) continue;
                        
                        wordList[curr][i] = c;
                        
                        auto it = hash.find( wordList[curr] );
                        if ( it == hash.end() or vis[it->second] ) continue ;
                        
                        vis[it->second] = true;
                        q.push( it->second );
                    }
                    
                    wordList[curr][i] = save;
                }
            }
        }
        return ( 0 );
    }
};