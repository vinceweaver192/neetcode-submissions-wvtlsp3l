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
    void reorderList(ListNode* head) {
        // user helper func
        head = helper(head, head->next);
    }

private:
    ListNode * helper(ListNode * root, ListNode * curr) {
        // base case
        if (curr == NULL) {
            return root; // only return root
        }

        // traverse current to end of list
        root = helper(root, curr->next);

        // end root if is null
        if (root == NULL) {
            return root;
        }

        // create temp for swapping but set to null
        ListNode * temp = NULL;

        // check if root overlapped with curr (for odd or even length lists)
        if (root == curr || root->next == curr) {
            // DONT return null
            // just set the next of curr to null to demonstrate the end
            curr->next = NULL;
        }
        else {
            // for all other cases, perform swap
            temp = root->next; // save the next node after root (1)
            root->next = curr; // set the next node to 6 (prev was 1)
            curr->next = temp;
        }

        return temp;
    }
};
