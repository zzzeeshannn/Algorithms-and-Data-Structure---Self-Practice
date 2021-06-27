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

    bool isFullTree(Node *root){
        // This function finds out if the current tree is a full tree
        if(root == NULL){
            return true;
        }
        else if(root->left == NULL && root->right == NULL){
            return true;
        }
        else if(root->left != NULL && root->right != NULL){
            return (isFullTree(root->left) && isFullTree(root->right));
        }
        return false;
    }
    bool isCompleteTree(Node *root, int index){
        // This function is used to find if the tree is a complete tree
        int totalNodes = countNodes(root);

        if(root == NULL){
            return true;
        }
        else if(index >= totalNodes){
            return false;
        }
        return (isCompleteTree(root->left, 2*index + 1) && isCompleteTree(root->right, 2*index + 2));
    }

    bool isIdentical(Node *root1, Node *root2){
        // This function checks if the two trees are identical
        if (root1 == NULL && root2 == NULL){
            return true;
        }
        else if(root1 != NULL && root2 != NULL){
            return ((root1->key == root2->key) && isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right));
        }
    }

    Node * successor(Node *root, int key){
        // This function finds the successor node given a key
        // Case 1: The current node is null
        if (root == NULL){
            return NULL;
        }
        // Case 2: The value of the node is less than or equal to the key
        if (root->key <= key){
            return successor(root->right, key);
        }
        // Case 3: The value of the node is greater than the key
        else{
            Node *left = successor(root->left, key);
            // Case 3.1: If left is not empty
            if(left != NULL){
                return left;
            }
            // Case 3.2: Left is empty
            else{
                return root;
            }
        }
    }

    Node * predecessor(Node *root, int key){
        // This function finds the node preceding the key
        // Case 1: Root is null
        if (root == NULL){
            return NULL;
        }
        // Case 2: Value of the node is >= the key
        else if(root->key >= key){
            return predecessor(root->left, key);
        }
        // Case 3: Value of node is < the key
        else{
            Node *right = predecessor(root->right, key);
            if(right != NULL){
                return right;
            }
            else{
                return root;
            }
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

    // Finding if the tree is a full tree
    bool full = tree.isFullTree(root);
    cout << endl;
    if(full){
        cout << "It is a full tree" << endl;
    }
    else{
        cout << "It is not a full tree" << endl;
    }

    // Finding if the tree is a complete tree
    bool complete = tree.isCompleteTree(root, 0);
    if(complete){
        cout << "It is a complete tree" << endl;
    }
    else{
        cout << "It is not a complete tree" << endl;
    }

    // Finding the successor
    int k = 10;
    Node *successor = tree.successor(root, k);
    cout << endl << "The successor of the key " << k << " is: " << successor->key << endl;

    // Finding the successor
    int m = 20;
    Node *predecessor = tree.predecessor(root, m);
    cout << "The predecessor of the key " << m << " is: " << predecessor->key << endl;
    return 0;
}