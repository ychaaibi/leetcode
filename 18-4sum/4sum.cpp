class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> solutions;
        vector<int>         solu(4);
        sort(nums.begin(), nums.end());
        
        if (nums.size() < 4) return (solutions);
        for (int i=0; i<nums.size()-3; i++)
        {
            for (int j=i+1; j<nums.size()-2; j++)
            {
                int s = j + 1, e = nums.size() - 1;
                long long   sum;

                while (s < e)
                {
                    sum = (long long)nums[i] + nums[j] + nums[s] + nums[e];
                    if (sum > (long long)target)
                        e--;
                    else if (sum < (long long)target)
                        s++;
                    else
                    {
                        solu[0] = nums[i];
                        solu[1] = nums[j];
                        solu[2] = nums[s++];
                        solu[3] = nums[e--];
                        solutions.push_back(solu);
                        for (int k=0; k<solutions.size() - 1; k++)
                        {
                            if (solutions[k][0] == solu[0] and solutions[k][1] == solu[1] and solutions[k][2] == solu[2] and solutions[k][3] == solu[3])
                            {
                                solutions.pop_back();
                                break ;
                            }
                            
                        }
                        while (s < e && nums[s] == nums[s - 1])
                            s++;
                        while (s < e && nums[e] == nums[e + 1])
                            e--;
                    }
                }
            }
        }
        return (solutions);
    }
};