class Solution {
public:
    int findMin(vector<int> &nums) {
        int ans = nums[0];
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            if (nums[l] < nums[r]) {
                ans = min(ans, nums[l]);
                break;
            }

            int m = l + (r - l) / 2; // mid
            ans = min(ans, nums[m]);

            if(nums[l] <= nums[m]){
              l = m + 1;
            } else {
              r = m - 1;
            }
        }

        return ans;
    }
};