#include <iostream>
using namespace std;

// Creating a Struct
struct Node
{
    // variables declared
    int Data_record;
    Node *next;
    Node *previous;
};

Node *insertingValues(Node *head, int data)
{
    Node *newNode = new Node();
    newNode->Data_record = data;
    newNode->next = NULL;
    newNode->previous = NULL;

    if (head == NULL) // Head = Null them Head becames NewNode
    {
        head = newNode;
    }
    else
    {
        Node *last = head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = newNode;
        newNode->previous = last;
    }
    return head;
}

void Function_Check(Node *head)
{
    Node *evenHead = NULL; // at start
    Node *oddHead = NULL;
    Node *evenTail = NULL;
    Node *oddTail = NULL; // pointing End

    while (head != NULL)
    {
        if (head->Data_record % 2 == 0) // logic for even
        {
            if (evenHead == nullptr)
            {
                evenHead = head;
                evenTail = head;
            }
            else
            {
                evenTail->next = head;
                head->previous = evenTail;
                evenTail = head;
            }
        }
        else
        {
            if (oddHead == NULL)
            {
                oddHead = head;
                oddTail = head;
            }
            else
            {
                oddTail->next = head;
                head->previous = oddTail;
                oddTail = head;
            }
        }
        head = head->next;
    }
    if (evenTail != NULL)
    {
        evenTail->next = NULL;
    }
    if (oddTail != NULL)
    {
        oddTail->next = NULL;
    }
    cout << "List of Even Are: " << endl;
    Node *current = evenHead;
    while (current != NULL)
    {
        cout << current->Data_record << " ";
        current = current->next;
    }
    cout << endl;

    cout << "List of Odd are: " << endl;
    current = oddHead;
    while (current != NULL)
    {
        cout << current->Data_record << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    int choice;
    int value;

    do
    {
        cout << "Menu:" << endl;
        cout << "1. Insert a value" << endl;
        cout << "2. View Even and Odd lists" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            head = insertingValues(head, value);
            break;
        case 2:
            Function_Check(head);
            break;
        case 0:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}