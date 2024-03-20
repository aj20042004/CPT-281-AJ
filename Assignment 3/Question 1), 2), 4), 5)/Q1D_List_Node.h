#ifndef Q1D_LIST_NODE_H
#define Q1D_LIST_NODE_H

#include <iostream>
using namespace std;


struct D_List_Node {
    int val;
    D_List_Node* next, * prev;
    D_List_Node(int val) : val(val), next(NULL), prev(NULL) {}
};

class Solution {
public:
    /** Creates a deep copy of a doubly-linked list.
        @param head: a pointer to the head node of the original list
        @return: a pointer to the head node of the deep copy
    */
    static D_List_Node* deep_copy(D_List_Node* head) {
        // Please copy this code to Canvas answer textbox.
        // Please add your code here to solve the problem.

        // Checking whether the head node exists or not
        if (!head) {
            return NULL;
        }

        // Creating a copy head node
        D_List_Node* copy_head = new D_List_Node(head->val);

        // Intializing the current node to the head node's next
        D_List_Node* current_node = head->next;

        // Marking the previous node as the copy head node initially
        D_List_Node* previous_node = copy_head;

        // Iterating through the original list create a copy
        while (current_node) {

            // Creating a new_node to copy the current node data
            D_List_Node* new_node = new D_List_Node(current_node->val);

            // Setting previous node's next pointer to the new node
            previous_node->next = new_node;

            // Setting the new node's previous pointer to the previous node
            new_node->prev = previous_node;

            // changing the previous node to the new node
            previous_node = new_node;

            // Moving the current node further
            current_node = current_node->next;
        }
        
        // returning the head node of the copied linked lists
        return copy_head;
   
    }

};

#endif
