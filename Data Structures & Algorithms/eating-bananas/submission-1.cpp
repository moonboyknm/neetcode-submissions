class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = ranges::max(piles); // max no. from the pile will be the last element in the array of k's.
        int ans = r; // setting it to r initally, it'll most likely be the answer.

        while (l <= r) {
            int k = (l + r) / 2; // k is the mid of the array of all possible k's

            long long EatingTime = 0; // how long it'll take koko to eat.
            for (int p : piles) {
                EatingTime += ceil(static_cast<double>(p) / k); 
            }

            /*
            Adds up the time it'll take koko to eat all the bananas in the pile 
            with current speed k.
            for e.g: [4,3,2] -> k = 2. 
            4 / 2 = 2. -> t = 2.
            3 / 2 = 1.5 -> t = 2 + 1.5 -> ceil(1.5 -> 2) -> 2+2 = 4
            --- Here ---
            1.5 means it will take koko 2 hours, we need to round up. 
            and for that we use the ceil() func.
            we also static cast p to a double so that the answer will return a 1.5 (p / k).
            then ceil rounds it up to 2.
            2 / 2 = 1 -> t = 4 + 1 = 5. 

            so we got EatingTime = 5. Then we compare.

            we're converting p to a double because it's from vector<int> piles, and it's
            originally an int so we static_cast<double> it during the division itself.
            then we get the ceil, we need to convert it into a double first to get 
            the round up version.
            */

            if (EatingTime > h){
                l = k + 1;
            } else {
                ans = k;
                r = k - 1;
            }

            /*
            Yes the traversal is a bit reversed here. 
            [1 2 3 4] = k
            1 will give a bigger eating time than 2, 2 will give a bigger time than 3.
            moving right will reduce eating time. moving left will increase it.

            so when eating time is > h, we move to the right, then we will get a k which 
            gives a smaller eating time.

            otherwise there are only 2 more possibilities:
            EatingTime = h or EatingTime < h

            if EatingTime < h: ans = k;
            if EatingTime = h: ans = k;

            we want to return the minimum value of k. I.E whichever one gives <= h the first
            time, from the array k = [1 2 3 4]

            so even if the current k works, there could also be another k which works.
            That's why we must check left side too.

            if (k DOESN'T WORK) {
                go right;
            }
            else {
                save k;
                go left;
            }
            */
        }
        return ans;
    }
};