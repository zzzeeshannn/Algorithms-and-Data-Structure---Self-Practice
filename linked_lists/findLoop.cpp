//
// Created by Zeeshan Shaikh on 6/28/21.
//

// This function is used to find a loop in the linked list
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
// This function is used in the findLoop function to count the number of nodes in the looped linked list
int countLoop(Node *node){
    Node *temp = node;
    int count = 1;
    while(temp->next != node){
        count += 1;
        temp = temp->next;
    }
    return count;
}
// Function to find the loop in a tree
int findLoop(Node *head){
    // Declaring two more linked lists
    // One will use a slow pointer increment
    // Other will use a fast pointer increment
    Node *slow = head;
    Node *fast = head;

    while( slow && fast && fast->next){
        // Increment
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast){
            return countLoop(slow);
        }
    }
    return 0;
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
    // Declaring the nodes here
    Node *head = NULL;
    Node *first = NULL;
    Node *second = NULL;
    Node *third = NULL;
    Node *fourth = NULL;

    head = new Node();
    first = new Node();
    second = new Node();
    third = new Node();
    fourth = new Node();

    head->data = 3;
    head->next = first;

    first->data = 4;
    first->next = second;

    second->data = 5;
    second->next = third;

    third->data = 6;
    third->next = fourth;

    // This creates a loop between first, second, third and fourth
    fourth->data = 7;
    fourth->next = first;

    // Detect loop here
    int count = findLoop(head);
    cout << "The number of nodes in the loop are: " << count << endl;
}