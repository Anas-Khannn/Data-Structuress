#include <iostream>

using namespace std;


// creating class
class Node {
    public:
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        if (front == nullptr) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void duplicateNodes() {
        Node* current = front;
        while (current != nullptr) {
            int data = current->data;
            Node* nextNode = current->next;
            for (int i = 1; i < data; ++i) {
                Node* duplicateNode = new Node();
                duplicateNode->data = data;
                duplicateNode->next = nextNode;
                current->next = duplicateNode;
                current = duplicateNode;
            }
            current = nextNode;
        }
    }

    void display() {
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int n;
    cout << "Enter Queue Elemnts: ";
    cin >> n;
    cout << "Enter the elements of the queue: ";
    for (int i = 0; i < n; ++i) {
        int data;
        cin >> data;
        q.enqueue(data);
    }

    cout << "Input Queue: ";
    q.display();
     //calling Duplicate Function
    q.duplicateNodes();

    cout << "Output Queue: ";
    q.display();

    return 0;
}
