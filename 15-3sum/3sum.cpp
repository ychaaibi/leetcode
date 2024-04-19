class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> solutions;
        vector<int>         sol(3);
        
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size() - 2; i++)
        {
            if (i && nums[i] == nums[i - 1]) continue ;
            int s = i + 1, e = nums.size() - 1, sum;
            while (s < e)
            {
                sum = nums[i] + nums[s] + nums[e];
                if (sum > 0)
                    e--;
                else if (sum < 0)
                    s++;
                else
                {
                    sol[0] = nums[i];
                    sol[1] = nums[s++];
                    sol[2] = nums[e--];
                    solutions.push_back(sol);
                    while (s < e && nums[s] == nums[s - 1])
                        s++;
                    while (s < e && nums[e] == nums[e + 1])
                        e--;
                }
            }
        }
        return (solutions);
    }
};