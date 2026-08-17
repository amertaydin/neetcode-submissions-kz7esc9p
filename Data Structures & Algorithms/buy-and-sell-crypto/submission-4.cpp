// what
// find the maximum profit

// which pattern and why
// sliding window because it's an array we traverse and find the optimal 

// how
// 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int l = 0;
        int r = 1;

        while (r < prices.size()) {
            int profit = prices[r] - prices[l];
            maxProfit = maxProfit > profit ? maxProfit : profit;

            if (prices[l] < prices[r]) {
                r++;
            } else {
                l = r;
                r++;
            }
        }


        return maxProfit;
    }
};
