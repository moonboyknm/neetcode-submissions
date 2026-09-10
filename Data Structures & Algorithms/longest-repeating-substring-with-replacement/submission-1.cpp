class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int l = 0, maxf = 0, res = 0;

        for (int r = 0; r < s.size(); r++){
            int window_size = r - l + 1;
            freq[s[r]]++;
            maxf = max (maxf, freq[s[r]]);

            while (window_size - maxf > k){
                freq[s[l]]--;
                l++;
                window_size = r - l + 1;
            }

            res = max (res , window_size);
        }

        return res;
    }
};
