// this is an implementation of a circular queue using arrays
/*
- the main difference between it and a normal queue is that is allows adding new elements
even after dequeueing
*/
#include <iostream>
#include <cstdlib>
using std::cin;
using std::cout;
class CircularQueue
{
private:
  int rear, front;
  int arr[5];

public:
  CircularQueue()
  {
    rear = front = -1;
    for (int i = 0; i < 5; i++)
    {
      arr[i] = 0;
    }
  }
  bool isEmpty()
  {
    return rear == front && front == -1;
  }
  bool isFull()
  {
    return (rear + 1) % 5 == front;
  }
  void enqueue(int item)
  {
    if (isFull())
    {
      cout << "Queue is Full\n";
    }
    else if (isEmpty())
    {
      rear = front = 0;
      arr[front] = item;
    }
    else
    {
      rear = (rear + 1) % 5;
      arr[rear] = item;
    }
  }
  void dequeue()
  {
    if (isEmpty())
    {
      cout << "Queue is Empty\n";
    }
    else if (rear == front)
    {
      arr[front] = 0;
      front = rear = -1;
    }
    else
    {
      arr[front] = 0;
      front = (front + 1) % 5;
    }
  }
  int count()
  {
    return rear + front - 1;
  }
  void display()
  {
    for (int i = 0; i < 5; i++)
    {
      cout << arr[i] << " \n";
    }
  }
};
int main()
{
  CircularQueue queue;
  int option, item;
  cout << "This is a Live Implementation of a circular queue\n";
  do
  {
    cout << "Please choose an option number - choose 0 to exit!\n";
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
      cout << "Please choose an item to enqueue\n";
      cin >> item;
      queue.enqueue(item);
      break;
    case 2:
      queue.dequeue();
      break;
    case 3:
      if (queue.isFull())
        cout << "Queue is Full\n";
      else
        cout << "Queue is not Full\n";
      break;
    case 4:
      if (queue.isEmpty())
        cout << "Queue is Empty\n";
      else
        cout << "Queue is not Empty\n";
      break;
    case 5:
      queue.display();
      break;
    case 6:
      cout << "The number of elements in the Queue is " << queue.count() << "\n";
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