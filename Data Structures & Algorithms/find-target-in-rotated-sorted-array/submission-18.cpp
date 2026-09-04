class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        // Find pivot (minimum element)
        while (l < r) {
            if (nums[l] <= nums[r])
                break;

            int mid = l + (r - l) / 2;

            if (nums[l] <= nums[mid])
                l = mid + 1;
            else
                r = mid;
        }

        int pivot = l;

        // Pick the sorted half
        l = 0;
        r = nums.size() - 1;

        if (pivot > 0 &&
            nums[0] <= target &&
            target <= nums[pivot - 1]) {
            r = pivot - 1;
        } else {
            l = pivot;
        }

        // Normal binary search
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target)
                return mid;

            if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return -1;
    }
};