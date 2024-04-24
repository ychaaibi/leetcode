class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l = n + m - 1 , p1 = m - 1, p2 = n - 1;
        
        while (p1 >= 0 or p2 >= 0)
        {
            if (p1 < 0)
                nums1[l--] = nums2[p2--];
            else if (p2 < 0)
                nums1[l--] = nums1[p1--];
            else if (nums1[p1] >= nums2[p2])
                nums1[l--] = nums1[p1--];
            else
                nums1[l--] = nums2[p2--];
        }
    }
};