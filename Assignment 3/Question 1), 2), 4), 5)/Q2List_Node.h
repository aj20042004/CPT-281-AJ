#ifndef Q2LIST_NODE_H
#define Q2LIST_NODE_H
#include <iostream>

using namespace std;

struct List_Node {
    int val;
    List_Node* next;
    List_Node(int val) : val(val), next(NULL) {}
};

class Solution_for_Q2 {
public:
    /** Removes the first occurrence of a value from a singly-linked list.
        @param head: a pointer to the head node of the list
        @param target: value to search (and remove) in the list
    */

    static void remove_first_occurrence(List_Node* head, int target) {
        // Please copy this code to Canvas answer textbox.
        // Please add your code here to solve the problem.

        // Returning none if there is no head exist
        if (!head) {
            return;
        }

        // Deleting the first node if it matches the target
        if (head->val == target) {

            // Marking the node to be deleted
            List_Node* head_to_be_deleted = head;

            // Updating the head
            head = head->next;

            // deleting the first node 
            delete head_to_be_deleted;
            return;
        }

        // Using current_node to iterate through the linked lists
        List_Node* current_node = head;

        // Checking whether current's next matches the target
        while (current_node->next && current_node->next->val != target) {

            current_node = current_node->next;
        }

        // Deleting the node that matches the target value
        if (current_node->next) {

            // Marking the node to be deleted
            List_Node* to_be_deleted = current_node->next;

            // Updating the current node's pointer
            current_node->next = current_node->next->next;

            // deleting the node
            delete to_be_deleted;
        }
       
    }
};


#endif
