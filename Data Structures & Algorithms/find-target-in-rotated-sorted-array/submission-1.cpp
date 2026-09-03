class Solution {
public:
    int search(vector<int>& n, int t) {
        int i;

        for(i = 0; i < n.size(); i++){
            if (n[i] == t){
                return i;
            }
        }

        return -1;
    }
};
