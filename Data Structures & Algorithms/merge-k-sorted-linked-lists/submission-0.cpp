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
        // edge case for empty list
        if (lists.empty()){
            return nullptr;
        }

        // take pairs of linked list and merge them each time
        while (lists.size() > 1) {
            // going to keep dividing list in half
            vector<ListNode*> combinedLists;

            // iterate through the list of pairs
            for (int i = 0; i < lists.size(); i+=2) {
                // create L1 and L2
                ListNode* L1 = lists[i];

                // practice doing conditional operations
                //ListNode* L2 = lists[i+1];
                // Important! 
                // - the lists can be of odd size, we want to check if it is
                //   odd, then set L2 to pick up a nullptr value (still ok for splits)
                ListNode* L2 = (i + 1) < lists.size() ? lists[i+1] : nullptr;

                // now merge the 2 lists
                combinedLists.push_back(mergeList(L1, L2));
            }

            // once the split lists have been merged into indices in combinedLists,
            // now update lists[] to become mergedLists;
            lists = combinedLists;
        }

        // at the end of the while loop, the list will just be a list of split lists
        // with the first and only index value holding the entire completed sorted 
        // merged lists
        return lists[0];
    }

    // this is a helper function created to simply merge 2 lists
    ListNode* mergeList(ListNode* L1, ListNode* L2) {
        // create a dummy or temp node to handle the merging into one
        ListNode temp;

        // create a tail ptr to keep track of merged lists
        ListNode* tailptr = &temp;

        // loop until atleast one list is empty
        // - Can add the remaining values from the other
        //   list to the current
        while (L1 != nullptr && L2 != nullptr){
            // compare the first vals of each sorted list
            // and append the smaller
            if (L1->val < L2->val){
                tailptr->next = L1; // ptr to ptr
                // increment L1 to next val
                L1 = L1->next;
            }
            else {
                // append and increment L2
                tailptr->next = L2;
                L2 = L2->next;
            }
            // move tailptr along
            tailptr = tailptr->next;
        }

        // now only one list or both are empty:
        if (L1 != nullptr){ // if not empty, grab rest of elements
            tailptr->next = L1;
        }
        if (L2 != nullptr){
            tailptr->next = L2;
        }

        // return the temp.next since it is not dereferenced
        // and current is empty, but the .next is the first val
        return temp.next;
    }
};
