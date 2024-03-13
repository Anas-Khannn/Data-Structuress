#include <iostream>
#include <string>
using namespace std;

// Node structure
struct Node
{
    string data;
    Node *next;
    Node(string d) : data(d), next(nullptr) {}
};

// linked list
class LinkedList
{
private:
    Node *head;

public:
    // constructur
    LinkedList() : head(nullptr) {}

    // Function to add a new node
    void addNodeToFront(string url)
    {
        Node *newNode = new Node(url);
        newNode->next = head;
        head = newNode;
    }

    // Function to remove the front node
    void removeFrontNode()
    {
        if (head == nullptr)
            return;

        Node *temp = head;
        head = head->next;
        delete temp;
    }

    // Function to check if  list is empty
    bool isEmpty()
    {
        return head == nullptr;
    }

    // Function to display the current page URL
    string getCurrentPage()
    {
        if (head != nullptr)
            return head->data;
        else
            return "No page currently available.";
    }
};

//  stack class for navigation
class NavigationStack
{
private:
    LinkedList backHistory;
    LinkedList forwardHistory;

public:
    // Function to navigate to a new page
    void navigate(string url)
    {
        backHistory.addNodeToFront(url);

        // Clearing forward history
        while (!forwardHistory.isEmpty())
        {
            forwardHistory.removeFrontNode();
        }
    }

    // Function to go back
    void goBack()
    {
        if (!backHistory.isEmpty())
        {
            
            forwardHistory.addNodeToFront(backHistory.getCurrentPage());
            
            backHistory.removeFrontNode();
        }
        else
        {
            cout << "Cannot go back. Navigation history is empty." << endl;
        }
    }

    // Function to go forward to the next page
    void goForward()
    {
        if (!forwardHistory.isEmpty())
        {
            
            backHistory.addNodeToFront(forwardHistory.getCurrentPage());
            
            forwardHistory.removeFrontNode();
        }
        else
        {
            cout << "Cannot go forward. Forward history is empty." << endl;
        }
    }

    //displaying the current page URL
    void displayCurrentPage()
    {
        cout << "Current page: " << backHistory.getCurrentPage() << endl;
    }
};

int main()
{
    NavigationStack browser;
    int choice;
    string url;

    do
    {
        // Display 
        cout << "\nMenu:\n"
             << "1. Navigate to a new page\n"
             << "2. Go back\n"
             << "3. Go forward\n"
             << "4. Display current page\n"
             << "5. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter URL: ";
            cin >> url;
            browser.navigate(url);
            break;
        case 2:
            browser.goBack();
            break;
        case 3:
            browser.goForward();
            break;
        case 4:
            browser.displayCurrentPage();
            break;
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}
