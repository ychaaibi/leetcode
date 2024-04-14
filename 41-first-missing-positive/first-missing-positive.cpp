class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for ( int i=0; i<nums.size(); i++ )
            if ( nums[i] <= 0 or nums[i] > n )
                nums[i] = n + 1;

        for ( int i=0; i<nums.size(); i++ )
        {
            if ( abs(nums[i]) == n + 1 )
                continue ;
            
            if ( nums[abs(nums[i]) - 1] == 0 )
                nums[abs(nums[i]) - 1] = -(n + 1);
            else if ( nums[abs(nums[i]) - 1] > 0 )
                nums[abs(nums[i]) - 1] *= -1;
        }

        for ( int i=0; i<n; i++ )
        {
            if ( nums[i] > 0 )
                return ( i + 1 );
        }
        return (n + 1);
    }
};