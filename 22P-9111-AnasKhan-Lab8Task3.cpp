#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to find the node in the BST 
TreeNode* searchBST(TreeNode* root, int val) {
    // If root is null or root's value matches the target value, return root
    if (root == nullptr || root->val == val) {
        return root;
    }
    
    // If target value is less than root's value, search left subtree
    if (val < root->val) {
        return searchBST(root->left, val);
    }
    
    // If target value is greater than root's value, search right subtree
    return searchBST(root->right, val);
}

// Function to perform inorder traversal of a binary tree 
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    // Construct the binary search tree
    TreeNode* root = nullptr;
    int n;
    cout << "Enter the number of nodes in the binary search tree: ";
    cin >> n;
    cout << "Enter the values of the nodes separated by space: ";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        if (root == nullptr) {
            root = new TreeNode(val);
        } else {
            TreeNode* current = root;
            while (true) {
                if (val < current->val) {
                    if (current->left == nullptr) {
                        current->left = new TreeNode(val);
                        break;
                    } else {
                        current = current->left;
                    }
                } else {
                    if (current->right == nullptr) {
                        current->right = new TreeNode(val);
                        break;
                    } else {
                        current = current->right;
                    }
                }
            }
        }
    }

    
    int target;
    cout << "Enter the target value to search for: ";
    cin >> target;

    // Search for the target value in the binary search tree
    TreeNode* result = searchBST(root, target);

    // Print the subtree rooted at the target value, if found
    if (result == nullptr) {
        cout << "Subtree rooted at value " << target << ": []" << endl;
    } else {
        cout << "Subtree rooted at value " << target << ": ";
        inorderTraversal(result);
        cout << endl;
    }

    // Deallocate memory
    

    return 0;
}
