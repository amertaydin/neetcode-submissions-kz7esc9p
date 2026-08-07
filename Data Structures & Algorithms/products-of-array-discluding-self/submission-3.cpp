// what
// I need to find the product of each index without them being there

// how
// calculate the number of 0's, if it's more than one then all of them should be 0
// otherwise just divide them if not 0

// which pattern
// I can solve it with vectors

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int numOfZeroes = 0;
        int product = 1;
        vector<int> result;

        for (int num : nums) {
            if (num == 0) numOfZeroes++;
        }

        if (numOfZeroes > 1) {
            for (int i = 0; i < nums.size(); i++) {
                result.push_back(0);
            }
            return result;
        }

        if (numOfZeroes == 1) {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 0) continue;
                product *= nums[i]; 
                
            }

            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 0) {
                    result.push_back(product);
                } else {
                    result.push_back(0);
                }
            }
            return result;
        }

        for (int num : nums) {
            product *= num;
        }

        for (int i = 0; i < nums.size(); i++) {
            result.push_back(product / nums[i]);
        }

        return result;
         
    }
};
