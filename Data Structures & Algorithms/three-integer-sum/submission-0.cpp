class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0) break; // if the array starts with a positive int after
                                  //sorting, that means the array will never have the triplets we want.
            
            if(i > 0 && nums[i] == nums[i-1]) continue; // i > 0 has to be, otherwise nums[i-1] doesn't exist. 
                                                        // next we check for duplicates, and skip them.
                                                        // duplicates are always next to each other in sorted arr.

            int l = i + 1, r = nums.size() - 1; // init pointers
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if (sum > 0){
                    r--;
                } else if (sum < 0){
                    l++;
                } else {
                    res.push_back({nums[i], nums[l], nums[r]}); // i is the fixed index of the array, here we found
                                                                // the first triplets so we return them and look for more.
                    l++; // look for more triplets. 
                    r--; 
                    while(l < r && nums[l] == nums[l-1]){
                        l++; // skip duplicates, duplicates will always be next to each other in a sorted array.
                    }
                }
            }
        }
        return res;
    }
};
