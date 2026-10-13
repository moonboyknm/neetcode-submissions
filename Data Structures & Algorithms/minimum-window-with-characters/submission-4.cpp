//#include <string>
//#include <vector>
//#include <climits>

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) return "";

        vector<int> count(128, 0);
        for (char c : t) {
            count[c]++;
        }

        int remaining = t.length(); 
        int min_start = 0, min_len = INT_MAX;
        int l = 0;

        for (int r = 0; r < s.length(); ++r) {
            if (count[s[r]] > 0) {
                remaining--;
            }
            count[s[r]]--;

            while (remaining == 0) {
                if (r - l + 1 < min_len) {
                    min_len = r - l + 1;
                    min_start = l;
                }

                count[s[l]]++;
                if (count[s[l]] > 0) {
                    remaining++;
                }
                l++;
            }
        }

        return min_len == INT_MAX ? "" : s.substr(min_start, min_len);
    }
};