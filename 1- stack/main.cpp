// implementing the stack data struture using arrays
#include <iostream>
#include <string>
#include <cstdlib>
using std::cin;
using std::cout;
class Stack
{
private:
  int top; // this keeps a track of the number of elements that are in the stack
  int arr[5];

public:
  // this is a constructor
  Stack()
  {
    top = -1;
    // making all the entries in the array 0
    for (int i = 0; i < 5; i++)
    {
      arr[i] = 0;
    }
  }
  bool isEmpty()
  {
    return top == -1;
  }
  bool isFull()
  {
    return top == 4;
  }
  void push(int item)
  {
    if (isFull())
      cout << "Stack is in overflow state\n";
    else
    {
      top++;
      arr[top] = item;
    }
  }
  int pop()
  {
    if (isEmpty())
    {
      cout << "Stack is in underflow state\n";
      return 0;
    }
    else
    {
      int popValue = arr[top];
      arr[top] = 0;
      top--;
      return popValue;
    }
  }
  int count()
  {
    return top + 1;
  }
  int peek(int index)
  {
    if (isEmpty())
    {
      cout << "Stack is in underflow state\n"; // means that there is no items in the stack
      return 0;
    }
    else
    {
      if (index >= 0 && index <= top)
        return arr[index];
      else
      {
        cout << "Index out of range!\n";
        return 0;
      }
    }
  }
  void change(int index, int value)
  {
    if (index >= 0 && index <= 4)
    {
      arr[index] = value;
      cout << "item changed at the index " << index << "\n";
    }
    else
      cout << "index " << index << " out of range\n";
  }
  void display()
  {
    for (int i = 4; i >= 0; i--)
    {
      cout << arr[i] << "\n";
    }
  }
};

int main()
{
  Stack s1;
  int option, item, index;
  do
  {
    cout << "What option would you like to perform? Select option number. Enter 0 to exit.\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. isEmpty()\n";
    cout << "4. isFull()\n";
    cout << "5. Peek\n";
    cout << "6. Count\n";
    cout << "7. change\n";
    cout << "8. display\n";
    cout << "9. clear screen\n";
    cin >> option;
    switch (option)
    {
    case 0:
      cout << "Exiting....\n";
      cout << "Program Exited succefully ✅\n";
      break;
    case 1:
      cout << "Enter an item to push in the stack\n";
      cin >> item;
      s1.push(item);
      break;
    case 2:
      cout << s1.pop() << "\n";
      break;
    case 3:
      if (s1.isEmpty())
        cout << "the stack is empty\n";
      else
        cout << "the stack is not empty\n";
      break;
    case 4:
      if (s1.isFull())
        cout << "the stack is full\n";
      else
        cout << "the stack is not full\n";
      break;
    case 5:
      cout << "Enter the index you of the item you want to peek\n";
      cin >> index;
      cout << s1.peek(index) << "\n";
      break;
    case 6:
      cout << "The number of element that are in the stack is " << s1.count() << "\n";
      break;
    case 7:
      cout << "Enter the index of the item you want to change\n";
      cin >> index;
      cout << "Enter the new item you want to put instead\n";
      cin >> item;
      s1.change(index, item);
      break;
    case 8:
      s1.display();
      break;
    case 9:
      system("clear");
      break;
    default:
      cout << "Please enter a valid option number!\n";
    };
  } while (option != 0);
  return 1;
}