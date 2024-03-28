#include <iostream>
#include <string>

using namespace std;

// class Created 
class FoodItem {
    public:
    string name;
    int price;
    FoodItem* next;
};

// Queue implementatation
class Queue {
private:
    FoodItem* front;
    FoodItem* rear;

public:
    Queue() {
    front = nullptr;
    rear = nullptr;
}

    // Function to add a new order
    void enqueue(string name, int price) {
        FoodItem* newItem = new FoodItem;
        newItem->name = name;
        newItem->price = price;
        newItem->next = nullptr;
        if (rear == nullptr) {
            front = rear = newItem;
        } else {
            rear->next = newItem;
            rear = newItem;
        }
        cout << "Order added to queue: " << name << endl;
    }

    // Function to remove the processed order from the queue
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }
        FoodItem* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    // Function to display the current orders in the queue
    void displayQueue() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Current Orders in Queue:" << endl;
        FoodItem* temp = front;
        while (temp != nullptr) {
            cout << temp->name << " - Rs" << temp->price << endl;
            temp = temp->next;
        }
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
    Queue orderQueue;
    int choice;
    string name;
    double price;

    do {
        cout << "\n=== Cafeteria Ordering System ===" << endl;
        cout << "1. Display Menu" << endl;
        cout << "2. Place Order" << endl;
        cout << "3. Process Orders" << endl;
        cout << "4. Display Current Orders" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "   Menu " << endl;
                cout << "1. Sandwich - Rs-599" << endl;
                cout << "2. Salad - Rs-499" << endl;
                cout << "3. Pizza - Rs-799" << endl;
                cout << "4. Coffee - Rs-299" << endl;
                break;
            case 2:
                cout << "\nEnter name of the item: ";
                cin >> name;
                cout << "Enter price of the item: ";
                cin >> price;
                orderQueue.enqueue(name, price);
                break;
            case 3:
                if (orderQueue.isEmpty()) {
                    cout << "No orders to process" << endl;
                } else {
                    cout << "Processing order..." << endl;
                    orderQueue.dequeue();
                }
                break;
            case 4:
                orderQueue.displayQueue();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
