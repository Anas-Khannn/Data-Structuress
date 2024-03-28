#include <iostream>

using namespace std;

int multiply(int a, int b) {
    // Base case: if b is 0, return 0
    if (b == 0) {
        return 0;
    }
    
    // Recursive case
    if (b > 0) {
        // If b is positive, recursively add a to the result of (b-1)
        return a + multiply(a, b - 1);
    } else {
        // If b is negative, recursively subtract a from the result of (|b|-1)
        return -multiply(a, -b);
    }
}

int main() {
    // Prompt the user to enter the values of a and b
    int a, b;
    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Enter the value of b: ";
    cin >> b;
    
    // Calculate the result of multiplying a and b using the multiply function
    cout << "Result of multiplying " << a << " and " << b << " is: " << multiply(a, b) << endl;
    
    return 0;
}
