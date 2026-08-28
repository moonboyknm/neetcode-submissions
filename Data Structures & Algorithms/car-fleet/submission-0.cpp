class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pair;
        for (int i = 0; i < position.size(); i++) {
            pair.push_back({position[i], speed[i]});
        }
        sort(pair.rbegin(), pair.rend());

        stack<double> stack;
        for (auto& p : pair) {
            double time = (double)(target - p.first) / p.second;

            if (!stack.empty() && time <= stack.top()) {
                continue;
            }

            stack.push(time);
        }

        return stack.size();
    }
};