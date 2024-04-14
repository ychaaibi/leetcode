class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        vector<int>             hash(1e6 + 1, 0);
        int                     p1, p2;
        long long               count = 1, ans;

        p1 = p2 = ans = 0;

        while ( p2 < nums.size() )
        {
            hash[nums[p2++]]++;

            if ( nums[p2 - 1] < minK or nums[p2 - 1] > maxK )
            {
                while ( p1 < p2 )
                    hash[nums[p1++]]--;
                continue ;
            }

            if ( hash[minK] == 0 or hash[maxK] == 0 )
            {
                count = 1;
                continue ;
            }

            while ( ( nums[p1] == minK and hash[minK] > 1 )
                or ( nums[p1] == maxK and hash[maxK] > 1 )
                or ( nums[p1] != minK and nums[p1] != maxK ) )
                hash[nums[p1++]]--, count++;

            ans += ( count );
        }

        return ( ans );
    }
};