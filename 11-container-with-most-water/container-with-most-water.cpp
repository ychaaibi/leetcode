class Solution {
public:
    int maxArea(vector<int>& height) {
        int s = 0, e = height.size() - 1;
        int mx = -1;
        
        while (s < e)
        {
            mx = max(mx, min(height[s], height[e]) * (e - s));
            if (height[s] < height[e])
                s++;
            else
                e--;
        }
        return (mx);
    }
};