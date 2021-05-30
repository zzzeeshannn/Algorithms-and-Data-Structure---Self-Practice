//
// Created by zee on 5/29/21.
//
#include <iostream>

using namespace std;

// Defining a node for the linked list
// This is how every node looks - one data module and one to store a reference to next node
// If linked list is empty, the head is NULL else the final node has NULL pointer
class Node{
public:
    int data;
    Node* next;
};

// Defining a function to add a new node at the start
// Input parameters: the current head node reference and the new data to be entered
void push(struct Node **head_ref, int new_data){
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    // Pointing the new node towards the current head node
    new_node->next = (*head_ref);
    // Assigning the new node as the head reference now
    (*head_ref) = new_node;
}

// Defining a function to add a new node at the end of the linked list
// Input Parameters: the current head node reference and the new data to be entered
void add_at_end(struct Node **head_ref, int new_data){
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    // Declaring a temporary node to traverse to the current last node
    struct Node *temp_node = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;
    while (temp_node->next != NULL){
        temp_node = temp_node->next;
    }
    temp_node->next = new_node;
}

// Defining a function to add a new node at any given location
// Input parameters: The node after which new node is required and the new data
// NOTE: We do not pass the reference of the node this time
void insert_after(struct Node *prev_node, int new_data){
    if (prev_node == NULL){
        std::cout << "ERROR: Given node cannot be NULL. \n";
        return;
    }
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Defining a function to delete a node with a given key
// Input parameters: head reference and key to be deleted
void delete_key(struct Node **head_ref, int key){
    struct Node *prev_node = NULL;
    struct Node *temp_node = *head_ref;

    // Checking if the head node has the key we need
    if (temp_node->data = key and temp_node != NULL){
        *head_ref = temp_node->next;
        delete temp_node;
        return;
    }
    else{
        while (temp_node->data != key and temp_node != NULL){
            prev_node = temp_node;
            temp_node = temp_node->next;
        }
        // If the key is not present in the list, the iteration will take the temp_node to the last node
        if (temp_node == NULL){
            std::cout << "The key is not present in the list";
        }
        prev_node->next = temp_node->next;
        delete temp_node;
    }
}

// Defining a function to delete a node from given position of the linked list
// Input Parameters: head reference and position of the node
void delete_position(struct Node **head_ref, int position){
    struct Node *temp_node = *head_ref;
    struct Node *prev_node = NULL;
    if (position == 0){
        *head_ref = temp_node->next;
        delete temp_node;
        return;
    }
    else{
        for (int i = 0; i < position-1; ++i) {
            prev_node = temp_node;
            temp_node = temp_node->next;
        }
        prev_node->next = temp_node->next;
        delete temp_node;
    }
}

// Function to print the list
// Input parameter is the head node
void printList(Node* n){
    while (n != NULL){
        std::cout << n->data << " ";
        n = n->next;
    }
}

int main(){
    // Need to make sure that all the pointers are assigned NULL
    Node* head = NULL;
    Node* first = NULL;
    Node* second = NULL;
    Node* third = NULL;

    // Declaring new nodes
    head = new Node();
    first = new Node();
    second = new Node();
    third = new Node();

    // Assigning values
    head->data = 10;
    head->next = first;

    first->data = 9;
    first->next = second;

    second->data = 8;
    second->next = third;

    third->data = 7;
    // Since this is the last node, we assign a NULL pointer to the next
    // Alternatively, we can leave this unassigned as we set it to NULL at the start of the main() function
    third->next = NULL;

    // Printing the list
    std::cout << "The current linked list looks like: ";
    printList(head);

    // Pushing a new value to the start of the linked list
    push(&head, 12);

    // Printing the list
    std::cout << "\nThe updated linked list after a push operation looks like: ";
    printList(head);

    // Adding a new value at the end of the linked list
    add_at_end(&head, 6);

    // Printing the list
    std::cout << "\nThe updated linked list after adding an element at the end looks like: ";
    printList(head);

    // Adding a new value after the head
    insert_after(head, 11);

    // Printing the list
    std::cout << "\nThe updated linked list after adding an element after the head node looks like: ";
    printList(head);

    // Deleting the node with key = 12
    delete_key(&head, 12);

    // Printing the list
    std::cout << "\nThe updated linked list after deleting an element looks like: ";
    printList(head);

    // Deleting the node at position 2
    delete_position(&head, 2);

    // Printing the list
    std::cout << "\nThe updated linked list after deleting an element at position 2 looks like: ";
    printList(head);
}