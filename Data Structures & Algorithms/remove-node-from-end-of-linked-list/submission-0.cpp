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
        // have a counter in post order traversal
        
        int size = 0;

        ListNode* cur = head;

        while (cur != NULL) {
            cur = cur->next;
            size++;
        }

        int nth = size - n;

        cur = head;
        ListNode* prev = NULL;
        while (nth > 0) {
            prev = cur;
            cur = cur->next;
            nth--;
        }
        // points to node to be removed

        // then head is getting removed
        if (prev == NULL) {
            return head->next;
        }
        else {
            prev->next = cur->next;
        }

        return head;
    }
};
