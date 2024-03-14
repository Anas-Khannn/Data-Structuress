#include <iostream>
#include<string>

using namespace std;

// creating Node class
class Node
{
public:
    
    //Variables
    string data; 
    Node *next;

    Node(string d)
    {
        data = d;
        next = nullptr;
    }
};

// circular linklist class
class CircularList
{
private:
    Node *head;
    int length;

public:
    CircularList()
    {
        head = nullptr;
        length = 0;
    }
    
    int getLength() const {
    return length;
}


    // insert 
    void insert(string val, int position)
    {
        if (position < 1 || position > length + 1)
        {
            cout << "Invalid input" << endl;
            return;
        }

        Node *n = new Node(val);

        if (head == nullptr)
        {
            head = n;
            head->next = head;
        }
        else if (position == 1)
        {
            Node *curr = head;
            while (curr->next != head)
            {
                curr = curr->next;
            }
            curr->next = n;
            n->next = head;
            head = n;
        }
        else
        {
            Node *curr = head;
            for (int i = 1; i < position - 1; i++)
            {
                curr = curr->next;
            }
            n->next = curr->next;
            curr->next = n;
        }
        length++;
    }

    // remove 
    void remove(int position)
    {
        if (head == nullptr || length == 0)
        {
            cout << "Empty" << endl;
            return;
        }
        if (position < 1 || position > length)
        {
            cout << "Invalid input" << endl;
            return;
        }

        if (position == 1)
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }

            if (length == 1)
            {
                cout << "Person Removed: " << head->data << endl; // removed person printed
                delete head;
                head = nullptr;
            }
            else
            {
                cout << "Person Removed: " << head->data << endl; 
                temp->next = head->next;
                Node *toDelete = head;
                head = head->next;
                delete toDelete;
            }
        }
        else
        {
            Node *curr = head;
            for (int i = 1; i < position - 1; i++)
            {
                curr = curr->next;
            }
            Node *toDelete = curr->next;
            curr->next = toDelete->next;

            cout << "Person Removed: " << toDelete->data << endl; // Print the removed person
            delete toDelete;
        }
        length--;
    }

    // josephus method.
    string josephus(string startPerson, int M)
    {
        if (!head || M <= 0 || length <= 0)
        {
            return "Invalid input"; // Invalid
        }

        Node *current = head;
        Node *prev = nullptr;

        while (length > 1)
        {
            // Moving the M-th person
            for (int i = 1; i < M + 1; i++)
            {
                prev = current;
                current = current->next;
            }

            // Removing the M-th person
            prev->next = current->next;
            Node *leavethecircle = current;
            current = current->next;
            if (leavethecircle == head)
            {
                head = current;
            }

            cout << "Person Removed: " << leavethecircle->data << endl; // Print 
            delete leavethecircle;
            length--;
        }

        return current->data;
    }
};

int main()
{
    CircularList circularList;

    cout << "--- Josephus Problem Simulator ---" << endl;

    int choice;
    string name, startPerson;
    int startChoice, jumpValue;
    bool clockwise;

    do
    {
        cout << "1. Add Person" << endl;
        cout << "2. Start Elimination Process" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
    cout << "Enter the name for the person: ";
    cin >> name;
    circularList.insert(name, circularList.getLength() + 1); // Insertion at the end
    cout << "Person " << name << " added to the circle." << endl;
    break;


        case 2:
            cout << "Enter the starting person's name: ";
            cin >> startPerson;
            cout << "Enter the jump value: ";
            cin >> jumpValue;
            cout << "Choose the direction (1. Clockwise / 2. Anticlockwise): ";
            cin >> startChoice;
            clockwise = (startChoice == 1) ? true : false;

            cout << "Elimination sequence:" << endl;
            cout << circularList.josephus(startPerson, jumpValue) << " is the survivor." << endl;
            break;

        case 3:
            cout << "Exiting the program..." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 3);

    return 0;
}
