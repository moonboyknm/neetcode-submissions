class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            swap(nums1, nums2);

        int total = nums1.size() + nums2.size();
        int half = (total + 1) / 2;

        int l = 0, r = nums1.size();

        while (l <= r) {
            int i = (l + r) / 2;
            int j = half - i;

            int nums1Left  = i > 0 ? nums1[i - 1] : INT_MIN;
            int nums1Right = i < nums1.size() ? nums1[i] : INT_MAX;

            int nums2Left  = j > 0 ? nums2[j - 1] : INT_MIN;
            int nums2Right = j < nums2.size() ? nums2[j] : INT_MAX;

            if (nums1Left <= nums2Right && nums2Left <= nums1Right) {
                if (total % 2)
                    return max(nums1Left, nums2Left);

                return (max(nums1Left, nums2Left)
                      + min(nums1Right, nums2Right)) / 2.0;
            }

            if (nums1Left > nums2Right)
                r = i - 1;
            else
                l = i + 1;
        }

        return -1;
    }
};