#include <iostream>
#include <string>
using namespace std;

// Creating A Struct Node
struct node
{
    // Variables
    string Song_Stitle;
    string Song_artist;
    node *next;
};

// Functions
void Beggining_Song(node *&head, string title, string artist) // Parameters Passing
{
    node *new_node = new node(); // Memory
    new_node->Song_Stitle = title;
    new_node->Song_artist = artist;
    if (head == NULL) 
    {
        new_node->next = new_node;
    }
    else
    {
        node *last = head;
        while (last->next != head)
        {
            last = last->next;
        }
        new_node->next = head;
        last->next = new_node;
    }
    head = new_node;
}
void Songs_AtEnding(node *&head)
{
    if (head == NULL) 
    {
        cout << "Currently is Empty" << endl;
        return;
    }

    node *last = head;
    while (last->next != head)
    {
        last = last->next;
    }
    if (last == head)
    {
        head = nullptr;
    }
    else
    {
        node *temp = head;
        while (temp->next != last)
        {
            temp = temp->next;
        }
        temp->next = head;
        delete last;
    }
}
void display(node *head) // Displaying Function
{
    if (head == NULL)
    {
        cout << "Currently is Empty" << endl;
        return;
    }

    node *current = head;
    do
    {
        cout << "Song: " << current->Song_Stitle << " by " << current->Song_artist << endl;
        current = current->next;
    } while (current != head);
}
int main()
{
    node *playSong = NULL;

    // Menu Driven
    while (1)
    {
        cout << "1. Add a Song at The start " << endl;
        cout << "2. Remove Song From the Last " << endl;
        cout << "3. Playlist to Be Displayed " << endl;
        cout << "4. Exit " << endl;
        cout << "Enter your choice: " << endl;
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter title of the Song You Like: "<<endl;
            string title;
            cin.ignore();
            getline(cin, title);
            cout << "Enter name of the artist you Like: "<<endl;
            string artist;
            getline(cin, artist);
            Beggining_Song(playSong, title, artist);
            break;
        }
        case 2:
            Songs_AtEnding(playSong);
            break;
        case 3:
            display(playSong);
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice.try again. " << endl;
        }
    }

    return 0;
}