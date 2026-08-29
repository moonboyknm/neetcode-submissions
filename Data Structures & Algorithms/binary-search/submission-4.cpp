/*
a --> array / nums
x --> target / marks the spot!
l --> left
r --> right

when mid is bigger than x, move right just behind mid. 
when mid is smaller than x, move left just after mid.

That's the secret.
*/

class Solution {
public:
    int search(vector<int>& a, int x) {
        int l = 0;
        int r = a.size() - 1;

        while (l <= r){
            int mid = l + ((r - l) / 2);

            if (a[mid] > x){
                r = mid - 1;
            } else if (a[mid] < x){
                l = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};