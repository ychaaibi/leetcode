class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int>   hash( nums.size(), INT_MIN );

        int mn = INT_MAX;

        for ( int i=0; i<nums.size(); i++ )
        {
            if ( mn < nums[i] )
                hash[i] = mn;
            else
                mn = nums[i];
        }

        set<int>    st;

        for ( int i = nums.size() - 1; i>=0; i-- )
        {
            st.insert(nums[i]);

            auto find = st.find( nums[i] );

            if ( find == st.begin() )
                continue ;

            if ( hash[i] != INT_MIN and *(--find) > hash[i] )
                return ( true );
        }

        return ( false );
    }
};