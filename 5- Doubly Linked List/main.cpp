#include <iostream>
#include <cstdlib>
using std::cin;
using std::cout;
class Node
{
private:
  int key;
  int data;
  Node *previous;
  Node *next;

public:
  Node()
  {
    previous = NULL;
    next = NULL;
    key = 0;
    data = 0;
  }
  Node(int key, int data)
  {
    previous = NULL;
    next = NULL;
    this->key = key;
    this->data = data;
  }
  // getters :
  int getKey()
  {
    return key;
  }
  int getData()
  {
    return data;
  }
  Node *getPrevious()
  {
    return previous;
  }
  Node *getNext()
  {
    return next;
  }
  // setters :
  void setKey(int key)
  {
    this->key = key;
  }
  void setData(int data)
  {
    this->data = data;
  }
  void setPrevious(Node *previous)
  {
    this->previous = previous;
  }
  void setNext(Node *next)
  {
    this->next = next;
  }
};

class DoublyLinkedList
{
private:
  Node *head;

public:
  DoublyLinkedList()
  {
    head = NULL;
  }
  DoublyLinkedList(Node *head)
  {
    this->head = head;
  }
  // getters :
  Node *getHead()
  {
    return head;
  }
  // operations
  // 1- checking if the node exist using the key
  Node *nodeExist(int key)
  {
    Node *temp = head;
    while (temp != NULL)
    {
      if (temp->getKey() == key)
      {
        return temp;
      }
      temp = temp->getNext();
    }
    return NULL;
  }
  // 2- append a node
  void appendNode(Node *node)
  {
    if (nodeExist(node->getKey()) != NULL)
    {
      cout << "Node already exist with key value : " << node->getKey() << ".\n";
    }
    else
    {
      if (head == NULL)
      {
        head = node;
        cout << "Node Appended as Head Node\n";
      }
      else
      {
        Node *temp = head;
        while (temp->getNext() != NULL)
        {
          temp = temp->getNext();
        }
        temp->setNext(node);
        node->setPrevious(temp);
        cout << "Node Appended\n";
      }
    }
  }
  // 3- prepend a node
  void prependNode(Node *node)
  {
    if (nodeExist(node->getKey()) != NULL)
    {
      cout << "Node already exist with key value : " << node->getKey() << ".\n";
    }
    else
    {
      if (head == NULL)
      {
        head = node;
        cout << "Node Prepended as Head Node\n";
      }
      else
      {
        head->setPrevious(node);
        node->setNext(head);
        head = node;
        cout << "Node Prepended\n";
      }
    }
  }
  // 4- insert a node after a certain key
  void insertNodeAfter(int key, Node *node)
  {
    if (nodeExist(node->getKey()) != NULL)
    {
      cout << "Node already exist with key value : " << node->getKey() << ".\n";
    }
    else
    {
      Node *temp = nodeExist(key);
      if (temp == NULL)
      {
        cout << "No node exist with the key value : " << key << ".\n";
      }
      else
      {
        if (temp->getNext() == NULL)
        {
          temp->setNext(node);
          node->setPrevious(temp);
          cout << "Node inserted at the end\n";
        }
        else
        {
          node->setNext(temp->getNext());
          temp->getNext()->setPrevious(node);
          node->setPrevious(temp);
          temp->setNext(node);
          cout << "Node inserted in between\n";
        }
      }
    }
  }

  // 5- delete a node
  void deleteNode(int key)
  {
    Node *temp = nodeExist(key);
    if (temp == NULL)
    {
      cout << "No node exist with the key value : " << key << ".\n";
    }
    else if (head == NULL)
      cout << "list empty\n";
    else
    {
      if (temp == head)
      {
        head = head->getNext();
        head->setPrevious(NULL);
        cout << "Node with the key value : " << temp->getKey() << " deleted\n";
      }
      else if (temp->getNext() == NULL)
      {
        temp->getPrevious()->setNext(NULL);
        cout << "Node deleted at the end\n";
      }
      else
      {
        temp->getPrevious()->setNext(temp->getNext());
        temp->getNext()->setPrevious(temp->getPrevious());
        cout << "Node deleted in between\n";
      }
    }
  }

  // 6- update a node
  void updateNode(int key, int data)
  {
    Node *temp = nodeExist(key);
    if (temp == NULL)
    {
      cout << "No node exist with the key value : " << key << ".\n";
    }
    else
    {
      temp->setData(data);
      cout << "Node data updated\n";
    }
  }

  // 7- display all nodes
  void display()
  {
    if (head == NULL)
    {
      cout << "list is empty\n";
    }
    else
    {
      Node *temp = head;
      while (temp != NULL)
      {
        cout << "key : " << temp->getKey() << " ---> data : " << temp->getData() << "\n";
        temp = temp->getNext();
      }
    }

    // traversing the other way around
    /*
    Node *temp = head;
    while (temp->getNext() != NULL)
    {
      temp = temp->getNext();
    }
    while (temp != NULL)
    {
      cout << "key : " << temp->getKey() << " ---> data : " << temp->getData() << "\n";
      temp = temp->getPrevious();
    }
    */
  }
};

int main()
{
  DoublyLinkedList list;
  int option;
  int data;
  int key, key2;

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
      break;
    case 1:
      cout << "Enter node key :\n";
      cin >> key;
      cout << "Enter node data :\n";
      cin >> data;
      node->setKey(key);
      node->setData(data);
      list.appendNode(node);
      break;
    case 2:
      cout << "Enter node key :\n";
      cin >> key;
      cout << "Enter node data :\n";
      cin >> data;
      node->setKey(key);
      node->setData(data);
      list.prependNode(node);
      break;
    case 3:
      cout << "Enter the key of the node you want to insert after :\n";
      cin >> key;
      cout << "Enter node key :\n";
      cin >> key2;
      cout << "Enter node data :\n";
      cin >> data;
      node->setKey(key2);
      node->setData(data);
      list.insertNodeAfter(key, node);
      break;
    case 4:
      cout << "Enter node key :\n";
      cin >> key;
      list.deleteNode(key);
      break;
    case 5:
      cout << "Enter node key:\n";
      cin >> key;
      cout << "Enter new Data :\n";
      cin >> data;
      list.updateNode(key, data);
      break;
    case 6:
      list.display();
      break;
    case 7:
      system("clear");
      break;
    default:
      cout << "Please enter a valid key!\n";
    }
  } while (option != 0);
  return 0;
}