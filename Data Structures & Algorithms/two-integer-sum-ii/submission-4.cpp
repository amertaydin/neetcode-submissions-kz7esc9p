// what
// I need to find the numbers who make the sum in a increased order

// which pattern
// two pointer

// how
// start from left and right, if too much decrease from right if less increase from left

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;

        while (l < r) {
            int num1 = numbers[l];
            int num2 = numbers[r];

            if (num1 + num2 == target) {
                return {l+1, r+1};
            }

            if (num1 + num2 > target) {
                r--;
            } else {
                l++;
            }
        }
    }
};
