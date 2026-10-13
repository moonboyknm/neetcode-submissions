#include <string>
#include <vector>
#include <climits>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.length() < t.length()) return "";

        // Fixed 128-element array for ASCII counts (defaults to 0)
        std::vector<int> count(128, 0);
        for (char c : t) {
            count[c]++;
        }

        int remaining = t.length(); // Total character count left to match
        int min_start = 0, min_len = INT_MAX;
        int l = 0;

        for (int r = 0; r < s.length(); ++r) {
            // If character was still needed, decrement total remaining count
            if (count[s[r]] > 0) {
                remaining--;
            }
            // Always decrement character count in window state
            count[s[r]]--;

            // When all target characters are contained in window
            while (remaining == 0) {
                if (r - l + 1 < min_len) {
                    min_len = r - l + 1;
                    min_start = l;
                }

                // Restore count of left character before shifting left boundary
                count[s[l]]++;
                // If character count becomes positive, it's now missing from window
                if (count[s[l]] > 0) {
                    remaining++;
                }
                l++;
            }
        }

        return min_len == INT_MAX ? "" : s.substr(min_start, min_len);
    }
};