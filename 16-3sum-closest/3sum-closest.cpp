class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int our_sum = 0;
        sort(nums.begin(), nums.end());
        
        our_sum = nums[0] + nums[1] + nums[2];
        for (int i=0; i<nums.size() - 2; i++)
        {
            int s = i + 1, e = nums.size() - 1;
            int sm;
            
            while (s < e)
            {
                sm = nums[i] + nums[s] + nums[e];
                our_sum = (abs(target - our_sum) < abs(target - sm)) ? our_sum : sm;
                if (sm < target)
                    s++;
                else
                    e--;
            }
        }
        return (our_sum);
    }
};