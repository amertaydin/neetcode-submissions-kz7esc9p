/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> nodes;

        ListNode *dummy = head;

        while (dummy) {
            nodes.push_back(dummy);
            dummy = dummy->next;
        }

        int nodeToRemove = nodes.size() - n;

        if (nodeToRemove == 0) {
            return head->next;
        } else {
            nodes[nodeToRemove - 1]->next = nodes[nodeToRemove]->next;
        }
    
        return head;
    }
};
