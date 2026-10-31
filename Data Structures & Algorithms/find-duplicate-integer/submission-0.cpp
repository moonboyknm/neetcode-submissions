class Solution {
public:
    int findDuplicate(const std::vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];

        // Phase 1: Fast & slow pointers
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        // Phase 2: Cycle entry detection
        fast = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};