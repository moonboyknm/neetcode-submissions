#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }

        // 1. Frequency map for target characters in s1
        vector<int> target(26, 0);
        int uniqueChars = 0;
        for (char c : s1) {
            if (target[c - 'a'] == 0) {
                uniqueChars++;
            }
            target[c - 'a']++;
        }

        // 2. Sliding window over s2
        vector<int> window(26, 0);
        int matchedUnique = 0;
        int k = s1.length();

        for (int i = 0; i < s2.length(); i++) {
            // Add right character into the window
            int right = s2[i] - 'a';
            window[right]++;
            
            // If this character just reached its required frequency
            if (target[right] > 0 && window[right] == target[right]) {
                matchedUnique++;
            }

            // Remove left character once window size exceeds k
            if (i >= k) {
                int left = s2[i - k] - 'a';
                
                // If this character was previously satisfying the requirement,
                // decrementing it will break that match
                if (target[left] > 0 && window[left] == target[left]) {
                    matchedUnique--;
                }
                window[left]--;
            }

            // If every unique character in s1 is matched with correct count
            if (matchedUnique == uniqueChars) {
                return true;
            }
        }

        return false;
    }
};