//
// Created by Zeeshan Shaikh on 6/26/21.
//

#include <iostream>

using namespace std;

class Node{
// Class Defining the nodes to be used in the tree
public:
    int key;
    Node *right;
    Node *left;

    Node(int value){
        // Constructor for the Node
        key = value;
        left = NULL;
        right = NULL;
    }
};

class BST{
public:
    Node * setRoot(int key){
        // This function is used to set the key as root node for a tree
        Node *root = new Node(key);
        return root;
    }

    Node * insert(Node *node, int key){
        // Function to add a key to the tree
        if(!node){
            // Case 1: Root is empty
            // The enter value is the new root of the tree
            node = new Node(key);
            return node;
        }
        else if(key > node->key){
            // Case 2: If key is greater than the key of the current node
            // It belongs to the right subtree
            node->right = insert(node->right, key);
        }
        else{
            // Case 3: If key is less than the key of the current node
            // It belongs to the left subtree
            node->left = insert(node->left, key);
        }
        return node;
    }

    void search(int key){
        // This function is used to search for a key in the tree
    }

    int countNodes(Node *root){
        // A recursive function to count the number of nodes in the tree
        // Time Complexity: O(N)
        if(!root){
            return 0;
        }
        else{
            return (1 + countNodes(root->left) + countNodes(root->right));
        }
    }
    int countLeafNodes(Node *root){
        // A recursive function to count the number of leaf nodes in the tree
        // Time Complexity: O(N)
        if(root == NULL){
            return 0;
        }
        if(root->left == NULL && root->right == NULL){
            return 1;
        }
        else{
            return (countLeafNodes(root->left) + countLeafNodes(root->right));
        }
    }
    int countNonLeafNodes(Node *root){
        // A recursive function to count the number of non-leaf nodes in the tree
        // Time Complexity: O(N)
        if(root == NULL){
            return 0;
        }
        if(root->left == NULL && root->right == NULL){
            return 0;
        }
        else{
            return (1 + countNonLeafNodes(root->left) + countNonLeafNodes(root->right));
        }

    }

    Node * kSmallest (Node *root, int k){
        // This function is used to find the k smallest element in the tree
        if (root == NULL){
            return NULL;
        }
        int value = countNodes(root->left) + 1;

        if(value == k){
            return root;
        }
        else if(value > k){
            return kSmallest(root->left, k);
        }
        else{
            // Why "k-value"?
            return kSmallest(root->right, k-value);
        }
    }
    Node * kLargest(Node *root, int k){
        // This function is used to find the k largest element in the tree
        // Case 1: Root is NULL
        if (root == NULL){
            return NULL;
        }
        // Find the length of right subtree
        int value = countNodes(root->right) + 1;
        // Case 1: length == k
        if (value == k){
            return root;
        }
        // Case 2: length > k
        else if(value > k){
            return kLargest(root->right, k);
        }
        // Case 3: length < k
        else{
            return kLargest(root->left, k);
        }
    }

    void Inorder(Node *root) {
        // This function prints the tree in sorted order
        if (!root){
            return;
        }
        Inorder(root->left);
        cout << root->key << " ";
        Inorder(root->right);
    }
};

int main(){
    BST tree;

    // Setting the tree root here
    Node *root = tree.setRoot(10);

    // Adding a few entries to the tree
    tree.insert(root, 45);
    tree.insert(root, 30);
    tree.insert(root, 55);
    tree.insert(root, 20);

    // Printing out the tree in-order
    cout << "The values in the tree are: ";
    tree.Inorder(root);
    cout << endl << endl;

    // Printing the number of nodes in the tree
    int count = tree.countNodes(root);
    cout << "The total number of nodes in the tree are: " << count << endl;

    // Printing the number of leaf nodes in the tree
    int leafCount = tree.countLeafNodes(root);
    cout << "The total number of leaf nodes in the tree are: " << leafCount << endl;

    // Printing the number of non-leaf nodes in the tree
    int NonLeafCount = tree.countNonLeafNodes(root);
    cout << "The total number of non-leaf nodes in the tree are: " << NonLeafCount << endl;

    // Finding the k smallest element
    cout << endl;
    int s = 2;
    Node *smallest = tree.kSmallest(root, s);
    cout << "The " << s << " smallest element in the tree is: " << smallest->key << endl;

    // Finding the k largest element
    int l = 2;
    Node *largest = tree.kLargest(root, l);
    cout << "The " << l << " largest element in the tree is: " << largest->key << endl;

    return 0;
}