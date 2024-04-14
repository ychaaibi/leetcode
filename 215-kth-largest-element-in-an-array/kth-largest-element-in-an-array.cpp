class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int                 val;   
        for (int i=0; i<nums.size(); i++) pq.push(nums[i]);
        while (k && pq.size())
        {
            cout << pq.top() << endl;
            k--;
            val = pq.top();
            pq.pop();
        }
        return (val);
    }
};