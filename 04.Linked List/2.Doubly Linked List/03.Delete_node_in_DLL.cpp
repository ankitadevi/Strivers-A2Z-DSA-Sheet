/*Given a doubly linked list and a position. The task is to delete a node from given position in a doubly linked list.

Example 1:

Input:
LinkedList = 1 <--> 3 <--> 4 
x = 3
Output: 1 3  
Explanation: After deleting the node at
position 3 (position starts from 1),
the linked list will be now as 1->3.
Example 2:

Input:
LinkedList = 1 <--> 5 <--> 2 <--> 9  
x = 1
Output: 5 2 9

APPROACH:-
1. The function `deleteNode` takes in two parameters: `head_ref`, which is a pointer to the head of the doubly linked list, and `x`, which represents the position of the node to be deleted.
2. The variable `temp` is initialized as the `head_ref`, which is a pointer to the head node of the linked list.
3. If `x` is equal to 1, it means the node to be deleted is the head node. In this case, the `temp` pointer is moved to the next node, and the new `temp` pointer is returned as the new head of the linked list. This effectively deletes the original head node.
4. If `x` is greater than 1, the code enters a loop that iterates `x-1` times. This loop moves the `temp` pointer to the node just before the position to be deleted.
5. After the loop, the variable `previous` is assigned the value of `temp`, which represents the node just before the position to be deleted.
6. The `previous->next` pointer is adjusted to skip over the node to be deleted by assigning it the value of `temp->next->next`.
7. The `temp->prev` pointer is adjusted to point to the `previous` node, updating the backward link.
8. Finally, the updated `head_ref` is returned.

CODE:-
*/
/**
class ListNode
{
 * Definition for doubly-linked list.
 *  public:
 *      int data;
 *      ListNode *prev;
 *      ListNode *next;
 *      ListNode() : data(0), prev(nullptr), next(nullptr) {}
 *      ListNode(int x) : data(x), prev(nullptr), next(nullptr) {}
 *      ListNode(int x, ListNode *prev, ListNode *next) : data(x), prev(prev), next(next) {}
};
*/

class Solution {
public:
    ListNode *deleteHead(ListNode *&head) {
        // Your code goes here
        if(head==NULL) return NULL;
        if(head->next==NULL){
            delete head;
            return NULL;
        }
        ListNode* curr=head->next;
        curr->prev=NULL;
        delete head;
        head=curr;
        return head;
    }
};


/*
Time Complexity:
- If the node to be deleted is the head node (position 1), the code performs a constant number of operations, resulting in a time complexity of O(1).
- If the node to be deleted is at any other position, the code traverses the linked list until it reaches the node just before the position to be deleted. This traversal requires visiting at most (x-1) nodes, where x is the position of the node to be deleted. Therefore, the time complexity in this case is O(x).
Space Complexity:
- The code uses a constant amount of extra space for variables (`temp`, `previous`). Hence, the space complexity is O(1).
In summary, the time complexity of the provided code is O(1) when deleting the head node and O(x) when deleting any other node, where x is the position of the node to be deleted. The space complexity is O(1).
*/
