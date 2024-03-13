#include <iostream>
#include <string>
using namespace std;

// Creating a Class
class Product
{
private:
    int id;
    string name;
    float price;
    int quantity;

public:
    // Initial Values
    Product()
    {
        id = 0;
        name = "N/A";
        price = 0.0;
        quantity = 0;
    }

    // constructor
    Product(int id, string name, float price, int quantity)
    {
        this->id = id;
        this->name = name;
        this->price = price;
        this->quantity = quantity;
    }

    // Getters and setters
    void setId(int id)
    {
        this->id = id;
    }

    void setName(string name)
    {
        this->name = name;
    }

    void setPrice(float price)
    {
        this->price = price;
    }

    void setQuantity(int quantity)
    {
        this->quantity = quantity;
    }

    int getId() const
    {
        return id;
    }

    string getName() const
    {
        return name;
    }

    float getPrice() const
    {
        return price;
    }

    int getQuantity() const
    {
        return quantity;
    }
};

class Node
{
public:
    Product data;
    Node *next;
    Node *prev;
};

class Inventory
{
private:
    Node *head;
    Node *tail;

public:
    Inventory()
    {
        head = nullptr;
        tail = nullptr;
    }

    // Functions
    void addProduct(int id, string name, float price, int quantity)
    {
        Node *newNode = new Node();
        newNode->data = Product(id, name, price, quantity);
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else if (id < head->data.getId())
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr && temp->next->data.getId() < id)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            if (temp->next != nullptr)
                temp->next->prev = newNode;
            temp->next = newNode;
            newNode->prev = temp;
            if (newNode->next == nullptr)
                tail = newNode;
        }
        cout << "Product added successfully!" << endl;
    }
    void removeProduct(int id)
    {
        if (head == nullptr)
        {
            cout << "Inventory is empty!" << endl;
            return;
        }

        Node *temp = head;
        while (temp != nullptr && temp->data.getId() != id)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Product with ID " << id << " not found!" << endl;
            return;
        }

        if (temp->prev != nullptr)
            temp->prev->next = temp->next;
        else
            head = temp->next;

        if (temp->next != nullptr)
            temp->next->prev = temp->prev;
        else
            tail = temp->prev;

        delete temp;
        cout << "Product removed successfully!" << endl;
    }
    void displayProducts()
    {
        if (head == nullptr)
        {
            cout << "Inventory is empty!" << endl;
            return;
        }

        Node *temp = head;
        cout << "ID\tName\t\tPrice\tQuantity" << endl;
        while (temp != nullptr)
        {
            cout << temp->data.getId() << "\t" << temp->data.getName() << "\t\t" << temp->data.getPrice() << "\t" << temp->data.getQuantity() << endl;
            temp = temp->next;
        }
    }

    void updatePrice(int id, float newPrice)
    {

        Node *temp = head;
        while (temp != nullptr && temp->data.getId() != id)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Product with ID " << id << " not found!" << endl;
            return;
        }

        temp->data.setPrice(newPrice);
        cout << "Price updated successfully!" << endl;
    }
    void findProduct(int id)
    {
        Node *temp = head;
        while (temp != nullptr && temp->data.getId() != id)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Product with ID " << id << " not found!" << endl;
            return;
        }

        cout << "Product found:" << endl;
        cout << "Name: " << temp->data.getName() << endl;
        cout << "Price: " << temp->data.getPrice() << endl;
        cout << "Quantity: " << temp->data.getQuantity() << endl;
    }
};

int main()
{
    Inventory inventory;
    int choice, id, quantity;
    string name;
    float price;

    do
    {
        cout << "\nMenu:" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. Remove Product" << endl;
        cout << "3. Display Products" << endl;
        cout << "4. Update Price" << endl;
        cout << "5. Find Product" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter product ID: ";
            cin >> id;
            cout << "Enter product name: ";
            cin >> ws;
            getline(cin, name);
            cout << "Enter product price: ";
            cin >> price;
            cout << "Enter product quantity: ";
            cin >> quantity;
            inventory.addProduct(id, name, price, quantity);
            break;
        case 2:
            cout << "Enter ID of the product to remove: ";
            cin >> id;
            inventory.removeProduct(id);
            break;
        case 3:
            inventory.displayProducts();
            break;
        case 4:
            cout << "Enter ID of the product to update price: ";
            cin >> id;
            cout << "Enter new price: ";
            cin >> price;
            inventory.updatePrice(id, price);
            break;
        case 5:
            cout << "Enter ID of the product to find: ";
            cin >> id;
            inventory.findProduct(id);
            break;
        case 6:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
