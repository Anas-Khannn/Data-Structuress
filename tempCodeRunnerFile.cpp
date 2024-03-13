#include <iostream>
using namespace std;
class List // class
{
private:
int *array;
int *current;
int length;
int Capacity;
public:
// Constructor & Deconstructor
List(int size)
{
array = new int[size];
length = 0;
current = NULL;
Capacity = size;
}
~List()
{
delete[] array;
}
// pointing at start
void start()
{
current = array;
}
// pointing at end
void tail()
{
current = array + (length - 1);
}
// back the pointer
void back()
{
current--;
}
// move the pointer in forward
void next()
{
current++;
}
void Full()
{
if (length == Capacity)
{
return;
}
}
// Time for Insertion
void Insert(int Value, int position)
{
if (length == Capacity)
{
cout << "List Is Full" << endl;
return;
}
// logic for insert at first position is
if (position < 0 || position > length + 1)
{
cout << "Not possible at this position" << endl;
return;
}
if (Capacity == 1) //// if the array is empty and the position is 1
{
current = array;
*current = Value;
}
tail();
for (int i = length; i >= position; i--)
{
*(current + 1) = *current;
back();
}
*(current + 1) = Value;
length++;
}
// Remove Functions
void Remove(int position)
{
if (length == 0)
{
cout << "List Is Empty" << endl;
return;
}
if (position < 0 || position > length + 1)
{
cout << "Not possible at this position" << endl;
return;
}
else
{
// start();
current = array + position - 1;
for (int i = position; i < length; i++) // Fixed condition in for

loop

{
*current = *(current + 1);
next();
}
length--;
}
}
void CopyList(List Obj1, List Obj2)
{
if (Obj1.length != Obj2.length)
{
cout << "Both ArrayLists must have the same length for copying." <<

endl;

return;
}
Obj1.start(); // Assuming you have a start() method in your ArrayList
class
Obj2.start();
for (int i = 0; i < Obj1.length; i++)
{
*Obj2.current = *Obj1.current;
Obj1.current++;
Obj2.current++;
}
cout << "The array is successfully copied." << endl;
Obj2.start();
for (int i = 0; i < Obj2.length; i++)
{
cout << *Obj2.current << " ";
Obj2.current++;
}
}
void reverse_list()
{
start();
int s = length;
int n = (length / 2);
for (int i = 0; i < n; i++)
{
int temp = *current;
*current = *(array + (s - 1));
*(array + (s - 1)) = temp;
current++;
s--;
}
}
void updated(int val, int pos)
{
if (pos < 1 || pos > length + 1)
{
cout << "Not possible at this position" << endl;
return;
}
if (length == 0)
{
cout << "List is empty" << endl;
return;
}
current = array + pos - 1;
*current = val;
}
void printlist()
{
if (length == 0)
{
cout << "List is empty" << endl;
return;
}
start();
for (int i = 0; i < length; i++)
{
cout << *current << " ";
next();
}
}
int Get(int position)
{
if (length == 0)
{
return -1;
}
if (position < 1 || position > length)
{
return -1;
}
current = array + position - 1;
return *current;
}
void Clear()
{
length = 0;
}
int find(int val)
{
start();
for (int i = 1; i <= length; i++)
{
if (*current == val)
{
cout << "Value is present at " << i << endl;
return i;
}
next();
}
cout << "Value is not present! " << endl;
return 0;
}
int lengthFunction()
{
return length;
}
void sort_in_ascending_order()
{
for (int i = 0; i < length - 1; i++)
{
start();
int *temp = current + 1;
for (int j = 0; j < length - i - 1; j++)
{
if (*temp < *current)
{
int a = *current;
*current = *temp;
*temp = a;
}
current++;
temp++;
}
}
start();
cout << "Array is successfully sorted in ascending order" << endl;
for (int i = 0; i < length; i++)
{
cout << *current << " ";
current++;
}
cout << endl;
}
};
int main()
{
int size;
//int arr[10];
cout << "Enter size for array." << endl;
cin >> size;
List obj(size); // creating object of the class
int arr[size];
cout << "Enter Elements of the array" << endl;
for (int i = 0; i < size; i++) {
cin >> arr[i];
obj.Insert(arr[i], i + 1); // Insert elements into List object
}

int input;
do // using this loop for creating menu driven program
{
cout << "Enter the option number. Press 0 to exit." << endl;
cout << "1) InsertElementAt()" << endl;
cout << "2) PrintList" << endl;
cout << "3) SearchElement()" << endl;
cout << "4) DeleteElement ()" << endl;
cout << "5) ReverseList()" << endl;
cout << "6) CopyList()" << endl;
cout << "7) Sort()" << endl;
cin >> input;
switch (input)
{
case 1:
int pos, value;
cout << "Enter the position" << endl;
cin >> pos;
cout << "Enter the value" << endl;
cin >> value;
obj.Insert(value, pos);
cout << endl;
break;
case 2:
obj.printlist();
cout << endl;
break;
case 3:
int val;
cout << "Enter the value you want to search." << endl;

cin >> val;
obj.find(val);
cout << endl;
break;
case 4:
int valll;
cout << "Enter the position you want to delete" << endl;
cin >> valll;
obj.Remove(valll);
cout << endl;
break;
case 5:
obj.reverse_list();
cout << endl;
break;
case 6:
{
List obj1(size); // creating object of the class
obj.CopyList(obj, obj1);
}
cout << endl;
break;
case 7:
obj.sort_in_ascending_order();
break;
default:
cout << "Enter correct option number." << endl;
break;
}
} while (input != 0);
return 0;
}