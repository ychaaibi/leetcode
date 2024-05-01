class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>  hash;

        for ( int i=0; i<nums.size(); i++ )
            hash.insert(nums[i]);
        
        int ans = 0;

        for ( int i=0; i<nums.size(); i++ )
        {
            if ( hash.find( nums[i] - 1 ) != hash.end() )
                continue ;
            
            int c = 0;

            for ( int k=nums[i]; hash.find( k ) != hash.end(); k++)
                c++;

            ans = max( c, ans );
        }

        return ( ans );
    }
};