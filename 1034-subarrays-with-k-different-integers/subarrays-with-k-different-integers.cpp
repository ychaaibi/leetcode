class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        vector<int>             hash(nums.size() + 1, 0);
        int                     p1, p2;
        int                     count = 1, ans, size = 0;

        p1 = p2 = ans = 0;

        while ( p2 < nums.size() )
        {
            size += !hash[nums[p2]];
            hash[nums[p2]]++;
            if ( size == k )
                break ;
            p2++;
        }

        while ( p2 < nums.size() )
        {
            while ( hash[nums[p1]] != 1 )
                hash[nums[p1++]]--, count++;

            ans += ( count );
            
            if ( ++p2 == nums.size()) break ;

            if ( !hash[nums[p2]])
            {
                hash[nums[p1++]]--;
                count = 1;
            }
            hash[nums[p2]]++;
        }

        return ( ans );
    }
};
