class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(const string& s : strs){
            res += to_string(s.size());
            res += '#';
            res += s;
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        size_t i = 0;

        while( i < s.size()){
            size_t j = s.find('#', i);
            int length = stoi(s.substr(i, j-i));

            res.push_back(s.substr(j+1, length));

            i = j + 1 + length;
        }

        return res;
    }
};