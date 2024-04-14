class Solution {
public:
    int ans;
    
    int get( int start, int end, int step, vector<int>& height )
    {   
        stack<int> st;
        int        mx = -1, next_end=start;
        
        for ( int i=start; i - step != end; i += step )
        {         
            if ( height[i] < mx )
            {
                st.push( i );
                continue ;
            }
            
            while ( !st.empty() )
            {
                ans += mx - height[st.top()];
                st.pop();
            }
            
            mx = height[i];
            st.push( i );
            next_end = i;
        }
        return ( next_end );
    }
    
    int trap(vector<int>& height) {
        int end = get(0, height.size() - 1, 1, height );
        get( height.size() - 1, end , -1, height );
        return ( ans );
    }
};