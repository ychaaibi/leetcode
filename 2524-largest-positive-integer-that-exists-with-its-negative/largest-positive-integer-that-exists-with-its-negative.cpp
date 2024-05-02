class Solution {
public:
    int findMaxK(vector<int>& nums) {
        vector<bool>    pos( 1001, false );
        vector<bool>    neg( 1001, false );

        for ( int i=0; i<nums.size(); i++ )
        {
            if ( nums[i] < 0 )
                neg[ -nums[i] ] = true;
            else
                pos[  nums[i] ] = true;
        }

        for ( int i=1000; i>0; i-- )
            if ( pos[i] and neg[i] )
                return ( i );
        return ( -1 );
    }
};