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

 // Solution Approach:
 // 1. iterate over the original list and merge the lists 2 at a time
 // 2. use a mergeList helper function to handle the merging of 2 lists
 
 // Some Gotchas:
 // - after merging 2 lists at a time, store the results back inside the original
 //   array 'lists'
 //   o Ex. lists[] => [10 different lists], after 1st iteration, => [5 sorted lists]
 //     last iteration => [1 sorted list]
 // - the number of total lists can be an odd number
 //   o MUST use a conditional assignment to determine if listB should equal lists[i+1]
 //     OR equal nullptr

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // check if list is empty and return null
        if (lists.empty()) {
            return nullptr;
        }

        // iterate until lists is of size 1
        while (lists.size() > 1) {
            // create a new vector to store the sub-sorted array
            vector<ListNode*> sorted;

            // iterate through the original list of k nodes
            for (int i = 0; i < lists.size(); i+=2) { // iterate by 2s
                // get the first and second value (2nd value MUST be a conditional for odd lists)
                ListNode* A = lists[i];

                // conditional
                ListNode* B = (i+1 < lists.size()) ? lists[i+1] : nullptr;

                // merge 2 lists using helper function
                sorted.push_back(mergeList(A, B));
            }
            // update lists to be the sorted sub-array
            lists = sorted;
        }
        // return the first value in lists[0]
        return lists[0];
    }

private:
    // create mergeList helper func
    ListNode* mergeList(ListNode* A, ListNode* B) {
        // create a temp to store the start of the sorted
        ListNode temp;
        ListNode* tailptr = &temp; // start pointer at a know start point, temp

        // loop and check while A and B have valid values in them
        while (A != nullptr && B != nullptr) {
            // if both of them are NOT null values, the we can compare values
            if (A->val < B->val) {
                // take left ptr
                tailptr->next = A;

                // traverse A node
                A = A->next;
            }
            else {
                // B is smaller or the same
                tailptr->next = B;

                // traverse B node
                B = B->next;
            }
            tailptr = tailptr->next;
        }

        // if one list is empty, get all the values from the other list
        if (A != nullptr) {
            // grab b
            // MUST set the ->next node with the remainder of the list
            tailptr->next = A;
        }
        else if (B != nullptr) {
            // same assignment, must use the node->next to set
            tailptr->next = B;
        }

        // return temp.next since it is the head of sorted combined list node
        return temp.next;
    }
};
