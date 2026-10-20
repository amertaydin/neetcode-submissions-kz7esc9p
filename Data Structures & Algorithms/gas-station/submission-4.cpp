class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // total gas available less than total cost, it's impossible
         int tank = 0;
         int total = 0;
         int start = 0; // at least one solution availabe

        for (int i = 0; i < gas.size(); i++) {
            int diff = gas[i] - cost[i];

            tank += diff;
            total += diff;

            if (tank < 0) {
                start = i + 1; // where we need to start
                tank = 0;
            }
        }


        return total >=0 ? start : -1;
    }
};
