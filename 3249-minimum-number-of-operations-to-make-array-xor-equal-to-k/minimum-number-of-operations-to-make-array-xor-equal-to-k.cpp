class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int> bits(32);
        bitset<32>  bit_k(k);
        int         ans = 0;

        for ( int i=0; i<nums.size(); i++ )
            for ( int b=0; b<32; b++ )
                bits[b] += ( nums[i] >> b ) & 1;

        for ( int i=0; i<32; i++ )
        {
            if ( !bit_k[i] )
                ans += ( bits[i] % 2 );
            else if ( !bits[i] )
                ans++;
            else
                ans += !( bits[i] % 2 );
        }

        return ( ans );
    }
};