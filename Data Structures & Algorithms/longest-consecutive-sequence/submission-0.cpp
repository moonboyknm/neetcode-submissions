class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        for(int num : s){
            if(s.find(num-1) == s.end()){
                int length = 1;
                int current = num;

                while(s.find(current+1) != s.end()){
                    current++;
                    length++;
                }

                longest = max(longest,length);
            }
        }

        return longest;
    }
};
