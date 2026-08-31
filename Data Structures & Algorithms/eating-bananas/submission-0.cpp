class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = ranges::max(piles); // max no. from the pile will be the last element in the array of k's.
        int ans = r; // setting it to r initally, it'll most likely be the answer.

        while (l <= r) {
            int k = (l + r) / 2; // k is the mid of the array of all possible k's

            long long TimetoEat = 0; // how long it'll take koko to eat.
            for (int p : piles) {
                TimetoEat += ceil(static_cast<double>(p) / k); 
            }

            /*
            Adds up the time it'll take koko to eat all the bananas in the pile with current speed k.
            for e.g: [4,3,2] -> k = 2. 
            4 / 2 = 2. -> t = 2.
            3 / 2 = 1.5 -> t = 2 + 1.5 -> ceil(1.5 -> 2) -> 2+2 = 4
            --- Here ---
            1.5 means it will take koko 2 hours, we need to round up. 
            and for that we use the ceil() func.
            we also static cast p to a double so that the answer will return a 1.5 (p / k).
            then ceil rounds it up to 2.
            2 / 2 = 1 -> t = 4 + 1 = 5. 

            so we got totalTime = 5. Then we compare.
            */

            if (TimetoEat > h){
                l = k + 1;
            } else {
                ans = k;
                r = k - 1;
            }
        }
        return ans;
    }
};