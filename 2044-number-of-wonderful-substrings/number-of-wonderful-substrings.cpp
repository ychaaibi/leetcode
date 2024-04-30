class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<bitset<10>, int>  hash;
        bitset<10>                      bits;
        long long                       ans = 0;

        hash[bits] = 1;

        for ( int i=0; i<word.size(); i++ )
        {
            bits[word[i] - 'a'] = !bits[word[i] - 'a'];
            hash[bits]++;

            ans += hash[bits] - 1;

            for ( int b=0; b<10; b++ )
            {
                bits[b] = !bits[b];

                ans += ( ( hash.find(bits) != hash.end() ) ? hash[bits] : 0 );

                bits[b] = !bits[b];
            }
        }

        return ( ans );
    }
};

// 145

// 10101

// 10101
// 10101

