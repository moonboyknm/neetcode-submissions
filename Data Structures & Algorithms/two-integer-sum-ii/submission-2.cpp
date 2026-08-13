class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0; // Pointer 1 at the start
        int j = numbers.size() - 1; // Pointer 2 at the end

        while(i < j){
            int sum = numbers[i] + numbers[j]; // Sum of ptrs

            if(sum == target){
                return {i+1, j+1}; // if found return +1 indices
            }
            else if(sum < target){
                i++; // meaning the target i value will be found farther right of the array.
            }
            else{
                j--; // meaning sum > target, meaning the target value will be found farther left of the array.
            }
        }

        return {}; // guaranteed solution, no need to return anything.
    }
};