class Solution {
public:
    pair<int,int>   calc( int diff, vector<int>& nums)
    {
        int             count_diff = 0, count_l_diff = 0;

        for ( int i=0; i<nums.size(); i++ )
        {
            count_diff += upper_bound( nums.begin(), nums.end(), nums[i] + diff ) - lower_bound( nums.begin(), nums.end(), nums[i] + diff );
            count_l_diff += upper_bound( nums.begin(), nums.end(), nums[i] + diff - 1) - ( nums.begin() + i + 1 );
        }

        return ( make_pair(count_l_diff, count_diff) );
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int l = nums[1] - nums[0], r = nums.back() - nums.front() + 1;

        for ( int i=1; i<nums.size(); i++ )
            l = min(l, nums[i] - nums[i - 1]);

        while ( l <= r )
        {
            int             md = (l + r) / 2;
            pair<int,int>   md_count = calc( md, nums );


            if ( md_count.second != 0 and k <= md_count.first + md_count.second and k > md_count.first )
                return ( md );
            
            if ( k > md_count.first + md_count.second )
                l = md + 1;
            else
                r = md;
        }     

        return ( 0 );
    }
};