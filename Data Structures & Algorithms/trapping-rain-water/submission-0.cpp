class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1; // my two pointers
        int lMax = height[l], rMax = height[r]; //keeping track
        int res = 0; // how much water stored

        while(l < r){
            if(lMax < rMax){
                l++;
                lMax = max(lMax, height[l]);
                res += lMax - height[l];
            } else {
                r--;
                rMax = max(rMax, height[r]);
                res += rMax - height[r];
            }
        }
        return res;
    }
};
