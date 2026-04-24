// what it wants
// try to arrange groups as group size and they need to increment by 1

// maybe sliding window, but greedy

// plan, check the size, if can be divided to 4 continue,
// sort them, if it's not incremented by 1 then put it in other group

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        map<int, int> freqMap;
        for (int num : hand) {
            freqMap[num]++;
        }

        sort(hand.begin(), hand.end());

        // 1, 2, 2, 3, 3, 4, 4, 5  1-1 2-2 3-3 4-4 5-1
        for (int num : hand) {
            if (freqMap[num] > 0) {
                for (int i = num; i < num + groupSize; i++) {
                    if (freqMap[i] == 0) return false;
                    freqMap[i]--;
                }
            }
        }

        return true;

        
    }
};
