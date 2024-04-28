#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;
};

class AVLTree {
public:
    Node* root;

    AVLTree() {
        root = nullptr;
    }

    // Function to check height
    int getHeight(Node* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    // Function to get balance
    int getBalanceFactor(Node* node) {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    // Function to right rotate
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        // Return new root
        return x;
    }

    // Function to left rotate subtree x
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        // Return new root
        return y;
    }

    // Recursive function to insert a key in the subtree rooted with node
    Node* insert(Node* node, int key) {
        // Standard BST insertion
        if (node == nullptr)
            return new Node{ key, nullptr, nullptr, 1 };

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else 
            return node;

        // Update height of this ancestor node
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        
        int balance = getBalanceFactor(node);

        

        // Left Left Case
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        
        return node;
    }

    // Function to print AVL tree in-order traversal
    void inOrder(Node* node) {
        if (node != nullptr) {
            inOrder(node->left);
            cout << node->key << " ";
            inOrder(node->right);
        }
    }

    // Function to test the AVL tree implementation
    void test() {
        int choice, value;

        while (true) {
            cout << "\nAVL Tree Operations:" << endl;
            cout << "1. Insert a node" << endl;
            cout << "2. Display tree (in-order traversal)" << endl;
            cout << "3. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                cout << "Enter value to be inserted: ";
                cin >> value;
                root = insert(root, value);
                cout << "Value inserted successfully." << endl;
                break;
            case 2:
                if (root == nullptr) {
                    cout << "Tree is empty." << endl;
                } else {
                    cout << "AVL Tree (in-order traversal): ";
                    inOrder(root);
                    cout << endl;
                }
                break;
            case 3:
                cout << "Exiting..." << endl;
                return;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
            }
        }
    }
};

int main() {
    AVLTree tree;
    tree.test();
    return 0;
}
