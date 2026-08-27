class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        int n = temps.size();
        stack<int> stack;
        vector<int> res(n,0);

        for(int i = 0; i < n; i++){
            int curr = temps[i];

            while(!stack.empty() && curr > temps[stack.top()]){
                int prev = stack.top();
                stack.pop();
                res[prev] = i - prev;
            }

            stack.push(i);
        }

        return res;
    }
};