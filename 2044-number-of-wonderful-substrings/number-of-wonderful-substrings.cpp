class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<int, int>         hash;
        int                             bits = 0;
        long long                       ans = 0;

        hash[bits] = 1;

        for ( int i=0; i<word.size(); i++ )
        {
            if ( bits & ( 1 << ( word[i] - 'a' ) ) )
                bits -= ( 1 << ( word[i] - 'a' ) );
            else
                bits += ( 1 << ( word[i] - 'a' ) );

            hash[bits]++;

            ans += hash[bits] - 1;

            for ( int b=0; b<10; b++ )
            {
                int save = bits;

                if ( bits & ( 1 << b ) )
                    bits -= ( 1 << b );
                else
                    bits += ( 1 << b );

                ans += ( ( hash.find(bits) != hash.end() ) ? hash[bits] : 0 );

                bits = save;
            }
        }

        return ( ans );
    }
};
