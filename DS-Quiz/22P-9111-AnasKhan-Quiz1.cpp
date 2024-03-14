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

    list()
    {
        head = NULL;
    }

    // Function to check if a character is a vowel
    bool isVowel(char ch)
    {
        ch = toupper(ch);
        return (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
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
                    Node *newVowelNode = new Node(ch);
                    newVowelNode->next = temp->next;
                    temp->next = newVowelNode;
                    temp = newVowelNode;
                }
            }
            else
            {
                // Consonant rule:
                Node *newConsonantNode = new Node('X');
                newConsonantNode->next = temp->next;
                temp->next = newConsonantNode;
                temp = newConsonantNode;
                Node *newCharNode = new Node(ch);
                newCharNode->next = temp->next;
                temp->next = newCharNode;
                temp = newCharNode;
            }
        }
        else if (isdigit(ch))
        {
            // Digit rule:
            int digit = ch - '0';
            digit *= digit;
            ch = '0' + digit;
            newNode->data = ch;
        }
    }

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
