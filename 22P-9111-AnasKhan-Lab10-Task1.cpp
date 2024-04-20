#include <iostream>

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* insert(Node* root, int key) {
        if (root == nullptr) {
            root = new Node(key);
        } else if (key < root->key) {
            root->left = insert(root->left, key);
        } else {
            root->right = insert(root->right, key);
        }
        return root;
    }

    Node* minValueNode(Node* root) {
        Node* current = root;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    Node* deleteNode(Node* root, int key) {
        if (root == nullptr) {
            return root;
        }

        if (key < root->key) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->key) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == nullptr || root->right == nullptr) {
                Node* temp = root->left ? root->left : root->right;
                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else {
                    *root = *temp;
                }
            } else {
                Node* temp = findMin(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key);
            }
        }

        return root;
    }

    void printInOrder(Node* node) {
        if (node != nullptr) {
            printInOrder(node->left);
            std::cout << node->key << " ";
            printInOrder(node->right);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int key) {
        root = insert(root, key);
    }

    void remove(int key) {
        root = deleteNode(root, key);
    }

    void printInOrder() {
        printInOrder(root);
        std::cout << "\n";
    }
};

int main() {
    BinarySearchTree bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    std::cout << "Inorder traversal of the original tree\n";
    bst.printInOrder();

    int valueToDelete;
    std::cout << "Enter value to delete: ";
    std::cin >> valueToDelete;
    bst.remove(valueToDelete);

    std::cout << "Inorder traversal after deletion\n";
    bst.printInOrder();

    return 0;
}
