class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        int n = temps.size();
        vector<int> res(n,0);
        stack<int> stack;

        for(int i = 0; i < n; i++){
            int curr = temps[i];

            while(!stack.empty() && curr > temps[stack.top()]){
                int saved = stack.top();
                stack.pop();
                res[saved] = i - saved;
            }

            stack.push(i);
        }

        return res;
    }
};