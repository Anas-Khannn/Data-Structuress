#include <iostream>

using namespace std;

// A binary tree node has data, pointer to left child
// and a pointer to right child
struct Node {
	int data;
	struct Node *left, *right;
};

// Utility function to create a new tree node
Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// Function to insert a new node in BST
Node* insertNode(Node* root, int data)
{
	if (root == NULL)
		return newNode(data);

	if (data < root->data)
		root->left = insertNode(root->left, data);
	else if (data > root->data)
		root->right = insertNode(root->right, data);

	return root;
}

// Function to perform inorder traversal of a BST
void inorderTraversal(Node* root)
{
	if (root == NULL)
		return;

	inorderTraversal(root->left);
	cout << root->data << " ";
	inorderTraversal(root->right);
}

// Function to perform preorder traversal of a BST
void preorderTraversal(Node* root)
{
	if (root == NULL)
		return;

	cout << root->data << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

// Function to perform postorder traversal of a BST
void postorderTraversal(Node* root)
{
	if (root == NULL)
		return;

	postorderTraversal(root->left);
	postorderTraversal(root->right);
	cout << root->data << " ";
}

// Function to find the smallest value in BST
int findSmallest(Node* root)
{
	if (root == NULL)
	{
		cout << "Tree is empty\n";
		return -1; // or throw an exception
	}

	while (root->left != NULL)
		root = root->left;

	return root->data;
}

// Function to count the nodes in BST
int countNodes(Node* root)
{
	if (root == NULL)
		return 0;

	return 1 + countNodes(root->left) + countNodes(root->right);
}

// Main function
int main()
{
	Node* root = NULL;
	int choice, data;

	bool running = true;
	while (running) {
		cout << "\n----- Binary Search Tree Operations Menu -----\n";
		cout << "1. Insert a new node\n";
		cout << "2. Inorder Traversal\n";
		cout << "3. Preorder Traversal\n";
		cout << "4. Postorder Traversal\n";
		cout << "5. Find the smallest value\n";
		cout << "6. Count nodes\n";
		cout << "7. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
			case 1:
				cout << "Enter data to insert: ";
				cin >> data;
				root = insertNode(root, data);
				break;
			case 2:
				cout << "Inorder Traversal: ";
				inorderTraversal(root);
				cout << endl;
				break;
			case 3:
				cout << "Preorder Traversal: ";
				preorderTraversal(root);
				cout << endl;
				break;
			case 4:
				cout << "Postorder Traversal: ";
				postorderTraversal(root);
				cout << endl;
				break;
			case 5:
				cout << "Smallest value in BST: " << findSmallest(root) << endl;
				break;
			case 6:
				cout << "Number of nodes in BST: " << countNodes(root) << endl;
				break;
			case 7:
				cout << "Exiting program.\n";
				running = false;
				break;
			default:
				cout << "Invalid choice. Please enter a valid choice.\n";
		}

	}

	return 0;
}
