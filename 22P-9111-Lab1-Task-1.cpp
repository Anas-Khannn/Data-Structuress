#include<iostream>
using namespace std;

void Display(int *Number, int Size)
{
    for(int *ptr = Number; ptr < Number + Size; ptr++)
    {
        cout << *ptr << " ";
    }
    cout << endl;  
}

bool Digit(int a, int *b, int Size)
{
    int sum = 0;
    for(int *p = b; p < b + Size; p++)
    {
        sum += *p;
    }
    return (a == sum);
}

int main()
{
    int x;
    int array[] = {1, 2, 3, 4, 5};
    int size = sizeof(array) / sizeof(array[0]);
    
    Display(array, size);
    cout << "-----------------------------------" << endl;

    cout << "Enter Number: ";
    cin >> x;
    cout << Digit(x, array, size) << endl;
    return 0;
}
