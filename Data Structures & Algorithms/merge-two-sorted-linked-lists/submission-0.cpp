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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //ListNode * curr1 = list1;
        //ListNode * curr2 = list2;

        // Create dummy root node to avoid inserting a node
        // into an empty list
        ListNode root(0);
        ListNode * sort = &root;

        // We want to compare both values of the lists, so check to make sure
        // that both lists are not empty.
        while(list1 && list2){
            if (list1->val < list2->val){
                // append the smaller val to the next node in the list
                sort->next = list1;

                // iterate to the next node of the smaller linked list val
                list1 = list1->next;
            }
            else {
                // append the smaller val to the next node in the list
                sort->next = list2;

                // iterate to the next node of the smaller linked list val
                list2 = list2->next;
            }
            // move sort pointer along
            sort = sort->next;
        }

        // At this point, only one list is empty and the other is not
        // Ex. list1 = [1] and list2 = [2]
        //     - if we do the last compare and take an item from list1,
        //       then we will always have a list that contains atleast 1
        //       item in it (maybe more)
        //
        // Solution:
        // - check which list is not empty
        // - add the next node of the sort list to point to
        //   the remaining values of the non-empty list
        if (list1) {
            sort->next = list1;
        } else {
            sort->next = list2;
        }

        // dummy root node isnt an actual value but it points to the top
        // of the sorted combined list
        // so we only need to return the value that it is pointing at
        //
        // *** root is NOT dereferenced, therefore must use a '.' operand
        // to reference the 'next' node which is the top of the sorted
        // combined list.
        return root.next;
    }
};
