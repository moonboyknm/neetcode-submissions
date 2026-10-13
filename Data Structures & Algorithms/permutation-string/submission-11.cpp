class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        
        if (n1 > n2) {
            return false;
        }

        // 1. Build the target frequencies and the first window's frequencies 
        vector<int> target(26, 0);
        vector<int> window(26, 0);
        
        for (int i = 0; i < n1; i++) {
            target[s1[i] - 'a']++;
            window[s2[i] - 'a']++;
        }

        // Check if the very first window is a match 🎯
        if (window == target) {
            return true;
        }

        // 2. Slide the window one character at a time 🪟
        for (int i = n1; i < n2; i++) {
            // Add the new character entering on the right ➕
            window[s2[i] - 'a']++;

            // Remove the old character leaving on the left ➖
            window[s2[i - n1] - 'a']--;

            // Check if the updated window matches 🎯
            if (window == target) {
                return true;
            }
        }

        return false;
    }
};