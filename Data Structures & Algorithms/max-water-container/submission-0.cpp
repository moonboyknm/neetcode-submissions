class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int res = 0;

        while (l < r) {
            int height = min(heights[l], heights[r]);
            int width = r - l;
            int area = height * width;
            res = max(res, area);

            if (heights[l] <= heights[r]) {
                l++;
            } else {
                r--;
            }
        }
        return res;
    }
};
