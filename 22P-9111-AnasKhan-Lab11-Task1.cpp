#include <iostream>

using namespace std;

// Node Tree
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function for creating a new node
Node* CreatingNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function for inserting  a node into BST
Node* insertion(Node* root, int value) {
    if (root == nullptr)
        return CreatingNode(value);
    if (value < root->data)
        root->left = insertion(root->left, value);
    else if (value > root->data)
        root->right = insertion(root->right, value);
    return root;
}

//  calculating   height
int height(Node* root) {
    if (root == nullptr)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

//  Checking as AVL or not
bool isAVL(Node* root) {
    if (root == nullptr)
        return true;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if (abs(leftHeight - rightHeight) <= 1 && isAVL(root->left) && isAVL(root->right))
        return true;
    return false;
}

// deleting the tree
void deleteTree(Node* root) {
    if (root == nullptr)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Node* root = nullptr;
    int value;
    cout << "Enter integers to create a binary search tree (-1 to end input):" << endl;
    

    while (true) {
        cin >> value;

        // Terminate input with -1
        if (value == -1) 
            break;
        root = insertion(root, value);
    }
    // Check if the constructed tree is AVL
    if (isAVL(root))
        cout << " AVL. " << endl;
    else
        cout << " Not AVL." << endl;
    // Delete the tree
    deleteTree(root);
    return 0;
}
