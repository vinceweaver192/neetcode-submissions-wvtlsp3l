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
    ListNode* reverseList(ListNode* head) {
        // Things to Do:
        //
        // 1. use link list methods using the '->' indicator
        // 2. Create a current and previous pointer
        //    - current will traverse the linked list
        //    - previous will keep track of the last 
        //
        // Singly Linked List:
        // Input:          1->2->3->4->5->NULL
        // Output:   NULL<-1<-2<-3<-4<-5

        ListNode* curr = head;
        ListNode* prev = NULL;

        while (curr != NULL){
            //cout << curr->val << ' ';

            // Create a temp instance of the current->next node.
            // ONLY PURPOSE: is to be used to continue basic iteration  
            // throughout the while loop.
            ListNode* temp = curr->next;
            
            // Begin reversing of linked list:
            // - Change the current->next node to NULL
            curr->next = prev;

            // Can now update the previous node with the next node
            // - prev will eventually become root node.
            // - setting prev = curr makes prev now equal '1'
            // - prev currently points to 1->NULL after first iteration
            prev = curr;

            // Lastly, need to make sure loop is able to iterate to next node 
            // in the original linked list.
            curr = temp;
        }

        return prev;
    }
};
