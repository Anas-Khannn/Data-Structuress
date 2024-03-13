#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000 // Maximum size 

char stack[MAX_SIZE];
int top = -1; // Top 

// Function to push 
void push(char c) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = c;
}

// Function to pop 
char pop() {
    if (top < 0) {
        printf("Stack underflow\n");
        return '\0'; // Return null if stack is empty
    }
    return stack[top--];
}

// Function to check if the string is balanced
bool isValid(char *s) {
    for (int i = 0; s[i] != '\0'; i++) {
        switch (s[i]) {
            case '(':
                push('(');
                break;
            case ')':
                if (pop() != '(') return false;
                break;
            case '[':
                push('[');
                break;
            case ']':
                if (pop() != '[') return false;
                break;
            case '{':
                push('{');
                break;
            case '}':
                if (pop() != '{') return false;
                break;
        }
    }
    return top == -1; // Stack should be empty if the string is balanced
}

int main() {
    char input[100];
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Check validity of a string\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a string: ");
                scanf("%s", input);
                printf("Result: %s\n", isValid(input) ? "true" : "false");
                break;
            case 2:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 2);

    return 0;
}
