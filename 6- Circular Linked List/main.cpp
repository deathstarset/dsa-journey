#include <iostream>
#include <cstdlib>
using std::cin;
using std::cout;

class Node
{
private:
  int key;
  int data;
  Node *next;

public:
  Node()
  {
    key = 0;
    data = 0;
    next = nullptr;
  }
  Node(int key, int data)
  {
    this->key = key;
    this->data = data;
  }
  int getKey()
  {
    return key;
  }
  int getData()
  {
    return data;
  }
  Node *getNext()
  {
    return next;
  }
  void setKey(int key)
  {
    this->key = key;
  }
  void setData(int data)
  {
    this->data = data;
  }
  void setNext(Node *next)
  {
    this->next = next;
  }
};

class CircularLinkedList
{
private:
  Node *head;

public:
  CircularLinkedList()
  {
    head = nullptr;
  }
  CircularLinkedList(Node *head)
  {
    this->head = head;
  }
  void setHead(Node *head)
  {
    this->head = head;
  }
  Node *getHead()
  {
    return head;
  }

  // # operations

  // 1- checking if a node exist
  Node *nodeExist(int key)
  {
    Node *temp = head;
    if (temp == nullptr)
    {
      return temp;
    }
    else
    {
      do
      {
        if (temp->getKey() == key)
        {
          return temp;
        }
        temp = temp->getNext();
      } while (temp != head);
    }
    return nullptr;
  }

  // 2- appending a node
  void appendNode(Node *node)
  {
    if (nodeExist(node->getKey()) != nullptr)
      cout << "Node already exist with key value : " << node->getKey() << ".\n";
    else
    {
      if (head == nullptr)
      {
        head = node;
        head->setNext(head);
        cout << "Node Appended As Head Node\n";
      }
      else
      {
        Node *temp = head;
        while (temp->getNext() != head)
        {
          temp = temp->getNext();
        }
        temp->setNext(node);
        node->setNext(head);
        cout << "Node Appended\n";
      }
    }
  }

  // 3- prepend node
  void prependNode(Node *node)
  {
    if (nodeExist(node->getKey()) != nullptr)
      cout << "Node already exist with key value : " << node->getKey() << ".\n";
    else
    {
      if (head == nullptr)
      {
        head = node;
        head->setNext(head);
        cout << "Node Prepended As Head\n";
      }
      else
      {
        Node *temp = head;
        while (temp->getNext() != head)
        {
          temp = temp->getNext();
        }
        temp->setNext(node);
        node->setNext(head);
        head = node;
        cout << "Node Prepended\n";
      }
    }
  }

  // 4- insert node after

  void insertAfter(int key, Node *node)
  {
    if (nodeExist(node->getKey()) != nullptr)
      cout << "Node already exist with key value : " << node->getKey() << ".\n";
    else
    {
      Node *temp = nodeExist(key);
      if (temp == nullptr)
        cout << "No node exist with the key value : " << key << ".\n";
      else
      {
        if (temp->getNext() == head)
        {
          temp->setNext(node);
          node->setNext(head);
          cout << "Node Inserted At End\n";
        }
        else
        {
          Node *temp2 = temp->getNext();
          temp->setNext(node);
          node->setNext(temp2);
          cout << "Node Inserted After\n";
        }
      }
    }
  };

  // 5- delete a node
  void deleteNode(int key)
  {
    Node *temp = nodeExist(key);
    if (temp == nullptr)
    {
      cout << "No node exist with the key value : " << key << ".\n";
    }
    else
    {
      if (temp == head)
      {
        if (temp->getNext() == head)
        {
          head->setNext(nullptr);
          head = nullptr;
          cout << "Head Node Deleted - List Is Empty\n";
        }
        else
        {
          while (temp->getNext() != head)
          {
            temp = temp->getNext();
          }
          Node *oldHead = head;
          head = head->getNext();
          temp->setNext(head);
          oldHead->setNext(nullptr);
          cout << "Head Node Deleted\n";
        }
      }
      else
      {
        Node *prevNode = head;
        while (prevNode->getNext() != temp)
        {
          prevNode = prevNode->getNext();
        }

        if (temp->getNext() == head)
          cout << "Node Deleted At Last\n";
        else
        {
          cout << "Node Deleted In Between\n";
        }
        prevNode->setNext(temp->getNext());
        temp->setNext(nullptr);
      }
    }
  }

  // 6- update node
  void updateNode(int key, int data)
  {
    Node *temp = nodeExist(key);
    if (temp == nullptr)
    {
      cout << "No node exist with the key value : " << key << ".\n";
    }
    else
    {
      temp->setData(data);
      cout << "Node Updated\n";
    }
  }

  // display list
  void display()
  {
    if (head == nullptr)
    {
      cout << "List Empty\n";
    }
    else
    {
      Node *temp = head;
      do
      {
        cout << "key -> " << temp->getKey() << " --- data -> " << temp->getData() << "\n";
        temp = temp->getNext();
      } while (temp != head);
    }
  }
};

;
int main()
{
  int option, key, data, key2;
  CircularLinkedList list;
  do
  {
    cout << "\nWhat operations you want to perform? Select option number. Enter 0 to exit\n";
    cout << "[1] => appendNode()\n";
    cout << "[2] => prependNode()\n";
    cout << "[3] => insertNodeAfter()\n";
    cout << "[4] => deleteNode()\n";
    cout << "[5] => updateNode()\n";
    cout << "[6] => display()\n";
    cout << "[7] => Clear Terminal\n";

    cin >> option;
    Node *node = new Node();

    switch (option)
    {
    case 0:
      cout << "Exiting Program....\n";
      break;
    case 1:
      cout << "Append Node\n";
      cout << "Enter Node Key\n";
      cin >> key;
      cout << "Enter Node Data\n";
      cin >> data;
      node->setKey(key);
      node->setData(data);
      list.appendNode(node);
      break;
    case 2:
      cout << "Prepend Node\n";
      cout << "Enter Node Key\n";
      cin >> key;
      cout << "Enter Node Data\n";
      cin >> data;
      node->setKey(key);
      node->setData(data);
      list.prependNode(node);
      break;
    case 3:
      cout << "Insert Node After\n";
      cout << "Enter Node Key You Want To Insert After\n";
      cin >> key2;
      cout << "Enter Node Key You Want To Add\n";
      cin >> key;
      cout << "Enter Node Data You Want To Add\n";
      cin >> data;
      node->setKey(key);
      node->setData(data);
      list.insertAfter(key2, node);
      break;
    case 4:
      cout << "Delete Node\n";
      cout << "Enter Node Key\n";
      cin >> key;
      list.deleteNode(key);
      break;
    case 5:
      cout << "Update Node\n";
      cout << "Enter Node Key\n";
      cin >> key;
      cout << "Enter Node New Data\n";
      cin >> data;
      list.updateNode(key, data);
      break;
    case 6:
      cout << "Display List\n";
      list.display();
      break;
    case 7:
      system("clear");
      break;
    default:
      cout << "Enter A Valid Option!\n";
    }
  } while (option != 0);
  return 0;
}