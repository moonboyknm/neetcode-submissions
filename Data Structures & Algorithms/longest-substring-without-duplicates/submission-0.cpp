class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int res = 0;
        unordered_map<char, int> map;

        for (int r = 0; r < s.size(); r++){
            if (map.find(s[r]) != map.end()){
                l = max(l , map[s[r]] + 1);
            }
            map[s[r]] = r;
            res = max (res , r - l + 1);
        }

        return res;
    }
};
