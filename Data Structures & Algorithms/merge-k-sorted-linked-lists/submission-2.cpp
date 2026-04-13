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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return {};
        for (int i = 1; i < lists.size(); i++) {
            lists[i] = mergeTwoList(lists[i], lists[i - 1]);
        }

        return lists.back();
    }

    ListNode* mergeTwoList(ListNode* l1, ListNode *l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *prev = dummy;

        while (l1 && l2) {
            if (l1->val >= l2->val) {
                dummy->next = l2;
                l2 = l2->next;
                dummy = dummy->next;
            } else if (l2->val > l1->val) {
                dummy->next = l1;
                l1 = l1->next;
                dummy = dummy->next;

            } 
        }

        if (l1) {
            dummy->next = l1;
        }

        if (l2) {
            dummy->next = l2;
        }
     
        return prev->next;
    }
};
