class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        int n = temps.size();
        vector<int> res(n, 0);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            int curr = temps[i];
            
            while (!st.empty() && curr > temps[st.top()]) {
                int prev = st.top();
                st.pop();
                res[prev] = i - prev;
            }
            st.push(i);
        }
        return res;
    }
};