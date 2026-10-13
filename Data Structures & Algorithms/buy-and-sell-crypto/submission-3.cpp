class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;

        int Psofar = 0;

        while (r < prices.size()){
            if (prices[r] > prices[l]){
                int currentP = prices[r] - prices[l];
                Psofar = max(Psofar, currentP);
            } else {
                l = r;
            }
            r++;
        }

        return Psofar;
    }
};
