class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;

        while (l < r){
            //skip non-alpha numeric chars
            while(l < r && !alphaNum(s[l])){
                l++;
            }
            while(l < r && !alphaNum(s[r])){
                r--;
            }
            // now compare the actual chars
            if(tolower(s[l]) != tolower(s[r])){
                return false;
            }
            // otherwise continue the loop
            l++; r--;
        }
        return true;
    }

    bool alphaNum(char c){
        return (
            c >= 'A' && c <= 'Z' ||
            c >= 'a' && c <= 'z' ||
            c >= '0' && c <= '9' );
    }
};
