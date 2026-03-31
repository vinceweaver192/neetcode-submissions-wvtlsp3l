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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // solution main idea
        // 1. iterate k times, create a dummy node to remember kth node, reverse all nodes within 1st k group
        // 2. can do recursion but aim for iterative solution

        // create a dummy node 
        ListNode* dummy = new ListNode(0, head);

        // create a pointer to the dummy
        // Purpose:
        // - track the node before the current group of 'k' nodes are reversed
        // - after reversing current 'k' nodes, this pointer is used to reconnect the reversed group
        //   back to the rest of the list
        // - initially points to dummy node which is useful for simplifying the handling of the first group
        // * after reversal, it becomes the new 'tail' of the reversed group (which was originally the group's first node)
        ListNode* groupPrev = dummy;

        // loop through the first k nodes
        while (true) {
            // find kth element from groupPrev
            // Call helper function, getkth()
            ListNode* kth = getkth(groupPrev, k);

            // base case
            // if there are fewer nodes than k left, break
            if (!kth) {
                break;
            }

            // if here, then list partition is valid
            // grab the pointer of the next element of kth
            // Purpose:
            // - tracks the node after the current group of 'k' nodes
            // - is used as a stopping condition for the reversal process and to reconnect the reversed group to
            //   the rest of the list
            // - initially set to the kth->next which is the node immediately after the kth node in the group
            ListNode* groupNext = kth->next; // pointer itself is the starting pointer of the current group

            // create nodes to start reversing the current k elements
            // Purpose:
            // - tracks the prevous node during the reversal of the current group
            // - is used to reverse the links in the group
            // - initially set to groupNext because, after reversal, the last node in the group should point to groupNext
            ListNode* prev = groupNext; // point prev to the pointer that is pointing to the node that points to the k+1 element 

            // Purpose:
            // - tracks the current node being processed during the reversal of the group
            // - is used to traverse through the k nodes being reversed and update their links
            // - initially set to groupPrev->next, which is the first node of the group being reversed
            ListNode* curr = groupPrev->next; // point current to the first node that dummy node initially pointed to (first node in singly linked list)

            // loop until current doesnt equal groupNext, which is the kth element
            while (curr != groupNext) {
                // start reversing nodes
                // create temp node and point it to the next pointer in curr
                // Purpose:
                // - temporarily store the next node in the original list during the reversal process
                // - it prevents losing the reference to the next node while reversing the link of the current node
                ListNode* temp = curr->next;

                // point curr.next to the prev node, reversing the link
                curr->next = prev;

                // move prev to curr node to update it for the next iteration
                prev = curr;

                // traverse curr to next
                curr = temp;
            }

            // now must reconnect the group
            // create another temp to store the current group
            // Purpose:
            // - stores the first node of the current group (before reversal)
            // - this node becomes the tail of the group (after reversal)
            ListNode* temp = groupPrev->next;

            // connect the groupPrev to the new head of the group
            // Purpose:
            // - connects the groupPrev (end of the previous group) to the new head of the reversed group (kth)
            groupPrev->next = kth;

            // move groupPrev to the end of the reversed group
            // Purpose:
            // updates groupPrev to point to the new tail of the reversed group for the next iteration
            groupPrev = temp;
        }
        // return the next of dummy, which is the root node post reversal
        return dummy->next;
    }

    // helper function
    ListNode* getkth(ListNode* groupPrev, int k) {
        // traverse the linked list while decrementing k
        while (k > 0 && groupPrev != nullptr) {
            groupPrev = groupPrev->next;
            k--;
        }
        return groupPrev;
    }
};
