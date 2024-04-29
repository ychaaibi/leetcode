class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int         ans = 0, curr = 0;

        for ( int i=0; i<nums.size(); i++ )
            curr ^= nums[i];

        bitset<32>  bit_k(k), bit_curr(curr);
        
        for ( int i=0; i<32; i++ )
            ans += ( bit_k[i] != bit_curr[i] );

        return ( ans );
    }
};