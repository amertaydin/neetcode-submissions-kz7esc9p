// check if I can complete a circuit from any of the indexes
// start with empty gas and fill it every cost one
// use greedy because I need to check every one of them
// but also for optimization we can remember the selections

// the plan
// for every index check if we can come back to the same index

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int currentGas = 0;
        int size = gas.size();

        for (int i = 0; i < size; i++) { // every index
            currentGas =  gas[i] - cost[i];
            
            if (currentGas < 0) continue;
            int j = (i + 1) % size;

            while (j != i) {
                currentGas = currentGas + gas[j] - cost[j];
                if (currentGas < 0) break;
                j = (j + 1) % size;
            }

            if (i == j) return i;
        }

        return -1;
    }
};
