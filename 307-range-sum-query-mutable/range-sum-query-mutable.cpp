class NumArray {
public:
    vector<int> segTree;
    int         n;

    NumArray(vector<int>& nums) {
        n = nums.size();

        segTree.resize( 4 * n );

        build( nums, 1, 0, n - 1 );
    }

    void build( vector<int>& nums, int node, int left, int right )
    {
        if ( left == right )
        {
            segTree[node] = nums[left];
            return ;
        }

        build( nums, node * 2, left, ( left + right ) / 2 );
        build( nums, node * 2 + 1, (left + right) / 2 + 1, right );

        segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
    }

    void _update( int node, int index, int val, int left, int right )
    {
        if ( index < left or index > right )
            return ;
        
        if ( index == left and left == right )
        {
            segTree[node] = val;
            return ;
        }

        if ( index >= left and index <= ( left + right ) / 2 )
            _update( node * 2, index, val, left, ( left + right ) / 2 );
        else
            _update( node * 2 + 1, index, val, ( left + right ) / 2 + 1, right );

        segTree[node] = segTree[2 * node + 1] + segTree[2 * node];
    }

    void update(int index, int val) {
        _update(1, index, val, 0, n - 1 );
    }
    
    int _sumRange( int node, int left, int right, int t_left, int t_right )
    {
        if ( left > t_right or right < t_left )
            return (0);

        if ( left >= t_left and right <= t_right )
            return (segTree[node]);

        int md  = (left + right) / 2;
        int ans = 0;

        if ( md >= t_left )
            ans += _sumRange( 2 * node, left, md, t_left, t_right );
            
        if ( md + 1 <= t_right )
            ans += _sumRange( 2 * node + 1, md + 1, right, t_left, t_right);

        return ( ans );
    }

    int sumRange(int left, int right) {
        return ( _sumRange( 1, 0, n - 1, left, right ) );
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */