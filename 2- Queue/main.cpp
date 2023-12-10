// implementing the queue data structure using arrays
#include <iostream>
#include <cstdlib>
using std::cin;
using std::cout;
class Queue
{
private:
  int rear, front; // thoses keep track of the rear and front sides of the queue
  int arr[5];

public:
  Queue()
  {
    rear = front = -1;
    for (int i = 0; i < 5; i++)
    {
      arr[i] = 0;
    }
  }
  bool isFull()
  {
    return rear == 4; // why is this : because the queue cannot accept any elements
    // until the last element is dequeued that's why
  }
  bool isEmpty()
  {
    return rear == -1 && front == -1;
  }
  void enqueue(int value)
  {
    if (isEmpty())
    {
      rear = front = 0;
      arr[rear] = value;
    }
    else if (isFull())
    {
      cout << "Queue is Full\n";
    }
    else
    {
      rear++;
      arr[rear] = value;
    }
  }
  int dequeue()
  {
    int value;
    if (isEmpty())
    {
      cout << "Queue is Empty!\n";
      return 0;
    }
    else if (rear == front)
    {
      value = arr[front];
      arr[front] = 0;
      rear = front = -1;
      return value;
    }
    else
    {
      value = arr[front];
      arr[front] = 0;
      front++;
      return value;
    }
  }
  void display()
  {
    for (int i = 0; i < 5; i++)
    {
      cout << arr[i] << " ";
    }
    cout << "\n";
  }
  int count()
  {
    return isEmpty() ? 0 : rear - front + 1;
  }
};
int main()
{
  Queue q1;
  int option, value;
  do
  {
    cout << "This is a Live Implementation of a Queue\n";
    cout << "Please choose a number between options\n";
    cout << "[1] => Enqueue()\n";
    cout << "[2] => Dequeue()\n";
    cout << "[3] => isFull()\n";
    cout << "[4] => isEmpty()\n";
    cout << "[5] => Display()\n";
    cout << "[6] => Count()\n";
    cout << "[7] => Clear Terminal\n";
    cin >> option;
    switch (option)
    {
    case 0:
      break;
    case 1:
      cout << "Please choose a value to enqueue\n";
      cin >> value;
      q1.enqueue(value);
      break;
    case 2:
      q1.dequeue();
      break;
    case 3:
      if (q1.isFull())
        cout << "Queue is Full\n";
      else
        cout << "Queue is not Full\n";
      break;
    case 4:
      if (q1.isEmpty())
        cout << "Queue is Empty\n";
      else
        cout << "Queue is not Empty\n";
      break;
    case 5:
      q1.display();
      break;
    case 6:
      cout << "The number of elements in the Queue is " << q1.count() << "\n";
      break;
    case 7:
      system("clear");
      break;
    default:
      cout << "Please choose a valid option number!\n";
    }
  } while (option != 0);
  return 0;
}