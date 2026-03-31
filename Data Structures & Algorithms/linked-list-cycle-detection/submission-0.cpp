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
    bool hasCycle(ListNode* head) {
        // Things to Do:
        // 
        // 1. Iterate through entire linked list
        // 2. Create a set of all the nodes that
        //    were visited
        // 3. Check if the next node in the list points to 
        //    a node that has been visited already, then 
        //    return true.

        ListNode * curr = head;
        unordered_set<ListNode*> visited;

        while (curr){

            // insert current node
            visited.insert(curr);

            // if next pointer exists in the set, return true
            if (visited.find(curr->next) != visited.end()){
                return true;
            }
            // iterate pointer
            curr = curr->next;
        }

        return false;
    }
};
