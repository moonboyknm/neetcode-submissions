class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l < r){
            if (nums[l] < nums[r])
                break;

            int mid = l + (r - l) / 2;

            if (nums[l] <= nums[mid]){
                l = mid + 1;
            } else 
                r = mid;
        }
        
        int pivot = l;
        l = 0, r = nums.size() - 1;

        if (target >= nums[pivot] && target <= nums[r])
            l = pivot;
        else 
            r = pivot - 1;

        while(l <= r){
            int mid = l + (r -l) / 2;

            if(target > nums[mid])
                l = mid + 1;
            else if (target < nums[mid])
                r = mid - 1;
            else 
                return mid;
        }

        return -1;
    }
};
