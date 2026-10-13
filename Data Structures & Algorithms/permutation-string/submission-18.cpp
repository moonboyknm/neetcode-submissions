class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        if (n1 > n2) return false;

        vector<int> target(26,0), window(26,0);

        for(int i = 0; i < n1; i++){
            target[s1[i] - 'a']++;
            window[s2[i] - 'a']++;
        } 

        if(window == target) return true; // Initialization over.

        // Sliding Window
        for(int i = n1; i < n2; i++){
            window[s2[i] - 'a']++;
            window[s2[i - n1] - 'a']--;
            if(window == target) return true;
        }

        return false;
    }
};