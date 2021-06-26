//
// Created by Zeeshan Shaikh on 6/26/21.
//

#include <iostream>

using namespace std;

class Node{

public:
    Node(int value){
        // Constructor for the Node
        key = value;
        left = NULL;
        right = NULL;
    }

    Node *right;
    Node *left;
// Class Defining the nodes to be used in the tree
int key;
};

class BST{
public:
    Node * setRoot(int key){
        // This function is used to set the key as root node for a tree
        Node *root = new Node(key);
        return root;
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
    tree.Inorder(root);
    return 0;
}