/**QUESTION:**

You are given the head of a doubly Linked List and a key. Your task is to delete all occurrences of the given key and return the new doubly Linked List.

**Example:**

Input: 
2 <-> 2 <-> 10 <-> 8 <-> 4 <-> 2 <-> 5 <-> 2
Key: 2
Output: 
10 <-> 8 <-> 4 <-> 5
Explanation: 
All occurrences of 2 have been deleted.

**APPROACH:**

To delete all occurrences of the given key from a doubly linked list, we can traverse the list and check each node's data. If the data matches the key, we handle three cases: deleting the first node, deleting the last node, and deleting a middle node. We update the pointers accordingly to remove the node from the list.

**TIME COMPLEXITY:** The time complexity is O(N), where N is the number of nodes in the doubly linked list.

**SPACE COMPLEXITY:** The space complexity is O(1) since we are modifying the given linked list in-place without using any extra space.

**CODE:**/

class Solution {
public:
    ListNode* deleteAllOccurrences(ListNode* head, int target) {

        ListNode* curr = head;

        while (curr) {

            if (curr->val == target) {

                ListNode* nextNode = curr->next;

                // deleting head
                if (curr == head) {
                    head = head->next;
                }

                // connect prev node
                if (curr->prev) {
                    curr->prev->next = curr->next;
                }

                // connect next node
                if (curr->next) {
                    curr->next->prev = curr->prev;
                }

                delete curr;

                curr = nextNode;
            }
            else {
                curr = curr->next;
            }
        }

        return head;
    }
};
