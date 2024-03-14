#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    char data;
    Node *next;
    
    Node(char Val)
    {
        data = Val;
        next = NULL;
    }
};

class list
{
public:
    Node *head;

    list() { head = NULL; }

    // Function to check if a character is a vowel
    bool isVowel(char ch)
    {
        ch = tolower(ch);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    // Function to insert a character according to specified rules
    void insert(char ch, int position)
    {
        Node *newNode = new Node(ch);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        // Apply rules based on the type of character
        if (isalpha(ch))
        {
            if (isVowel(ch))
            {
                // Vowel rule: repeat character based on position
                for (int i = 0; i < position; ++i)
                {
                    newNode = new Node(ch);
                    newNode->next = temp->next;
                    temp->next = newNode;
                    temp = newNode;
                }
            }
            else
            {
                // Consonant rule: append 'X' followed by position
                newNode = new Node('X');
                newNode->next = temp->next;
                temp->next = newNode;
                temp = newNode;
                newNode = new Node(ch);
                newNode->next = temp->next;
                temp->next = newNode;
                temp = newNode;
            }
        }
        else if (isdigit(ch))
        {
            // Digit rule: square the number
            int digit = ch - '0';
            digit *= digit;
            ch = '0' + digit;
            newNode->data = ch;
        }
    }

    // Function to display the list
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    list charList;
    for (int i = 0; i < input.length(); ++i)
    {
        charList.insert(input[i], i + 1);
    }

    cout << "Processed string: ";
    charList.display();

    return 0;
}
