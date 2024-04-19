class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int p1 = 1;
        int p2 = 1;

        while (p2 < nums.size())
        {
            if (nums[p2] == nums[p1 - 1]) p2++;
            else
                nums[p1++] = nums[p2];
        }
        return (p1);
    }
};