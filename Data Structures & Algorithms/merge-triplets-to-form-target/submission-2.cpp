// what it asks of me
// from inputs I need to merge triplets, to see if it's equal to target

// what pattern -> greedy

// what's the plan
// for target, I need to check if we have the frequency 

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_set<int> good;

        for (auto triplet : triplets) {
            if (triplet[0] > target[0] ||
                triplet[1] > target[1] ||
                triplet[2] > target[2]) continue;

            for (int i = 0; i < triplet.size(); i++) {
                if (triplet[i] == target[i]) good.insert(i);
            }
        }


        return good.size() == 3;
    }
};
