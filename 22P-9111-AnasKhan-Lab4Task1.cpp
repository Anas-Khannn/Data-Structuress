#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    int IdNum;
    float GPA;
    string Student_Name;
    Student *next;
    
    Student(int id, string name, float gpa) {
        IdNum = id;
        Student_Name = name;
        GPA = gpa;
        next = nullptr;
    }

    // Getters
    int getId() {
        return IdNum;
    }
    
    float getGPA() {
        return GPA;
    }
    
    string getName() {
        return Student_Name;
    }
    
    Student *getNext() {
        return next;
    }
};

class StudentList {
private:
    Student *head;
    int count;
    double totalGPA;
    
public:
    StudentList() {
        head = nullptr;
        count = 0;
        totalGPA = 0;
    }

    ~StudentList() {
        while (head != nullptr) {
            Student *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addStudent(int id, string name, float gpa) {
        Student *newStudent = new Student(id, name, gpa);
        newStudent->next = head;
        head = newStudent;
        count++;
        totalGPA += gpa;
        cout << "Student added successfully." << endl;
    }

    void removeStudent(int id) {
        if (head == nullptr) {
            cout << "No student records found." << endl;
            return;
        }

        Student *current = head;
        Student *prev = nullptr;

        while (current != nullptr && current->getId() != id) {
            prev = current;
            current = current->getNext();
        }

        if (current == nullptr) {
            cout << "Student not found." << endl;
            return;
        }

        if (prev != nullptr) {
            prev->next = current->next;
        } else {
            head = current->next;
        }

        totalGPA -= current->getGPA();
        delete current;
        count--;
        cout << "Student removed successfully." << endl;
    }

    void searchStudent(int id) {
        Student *current = head;

        while (current != nullptr && current->getId() != id) {
            current = current->getNext();
        }

        if (current == nullptr) {
            cout << "Student not found." << endl;
            return;
        }

        cout << "Student found:" << endl;
        cout << "ID: " << current->getId() << ", Name: " << current->getName() << ", GPA: " << current->getGPA() << endl;
    }

    void displayStudents() {
        if (head == nullptr) {
            cout << "No student records found." << endl;
            return;
        }

        cout << "Student Records:" << endl;
        Student *current = head;

        while (current != nullptr) {
            cout << "ID: " << current->getId() << ", Name: " << current->getName() << ", GPA: " << current->getGPA() << endl;
            current = current->getNext();
        }
    }

    void calculateAverageGPA() {
        if (count == 0) {
            cout << "No student records found." << endl;
            return;
        }

        double averageGPA = totalGPA / count;
        cout << "Average GPA: " << averageGPA << endl;
    }
};

int main() {
    StudentList studentList;
    int choice;

    do {
        cout << "Welcome to the Student Registration System!" << endl;
        cout << "1. Add a student" << endl;
        cout << "2. Remove a student" << endl;
        cout << "3. Search for a student" << endl;
        cout << "4. Display all students" << endl;
        cout << "5. Calculate average GPA" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id;
                string name;
                float gpa;
                cout << "Enter student ID: ";
                cin >> id;
                cout << "Enter student name: ";
                cin >> name;
                cout << "Enter student GPA: ";
                cin >> gpa;
                studentList.addStudent(id, name, gpa);
                break;
            }
            case 2: {
                int id;
                cout << "Enter student ID to remove: ";
                cin >> id;
                studentList.removeStudent(id);
                break;
            }
            case 3: {
                int id;
                cout << "Enter student ID to search: ";
                cin >> id;
                studentList.searchStudent(id);
                break;
            }
            case 4: {
                studentList.displayStudents();
                break;
            }
            case 5: {
                studentList.calculateAverageGPA();
                break;
            }
            case 6:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 6);

    return 0;
}
