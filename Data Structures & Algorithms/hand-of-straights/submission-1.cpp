class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // sort and make a frquency map
        sort(hand.begin(), hand.end()); // needed for greedy approach
        unordered_map<int, int> freqMap;

        for (int i : hand) {
            freqMap[i]++;
        }

        for (int num : hand) {
            if (freqMap[num] == 0) continue; // if no frequency continue

            for (int j = 0; j < groupSize; j++) {
                if (freqMap[num + j] == 0) return false;
                freqMap[num + j]--;
            }
        }

        return true;
    }
};
