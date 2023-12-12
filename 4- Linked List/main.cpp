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
    next = NULL;
  }
  Node(int key, int data)
  {
    this->key = key;
    this->data = data;
    next = NULL;
  }
  // getters
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
  // setters
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
class SinglyLinkedList
{
private:
  Node *head;

public:
  SinglyLinkedList()
  {
    head = NULL;
  }
  SinglyLinkedList(Node *head)
  {
    this->head = head;
  }
  // getter
  Node *gethead()
  {
    return head;
  }
  // operations
  // 1- check if node exists using key value
  Node *nodeExist(int key)
  {
    Node *temp = head;
    if (temp != NULL)
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
  // 2- append a node to the list
  void appendNode(Node *node)
  {
    if (nodeExist(node->getKey()) != NULL)
    {
      cout << "key already used by another node\n";
    }
    else
    {
      if (head == NULL)
      {
        head = node;
        cout << "Node Appended\n";
      }
      else
      {
        Node *temp = head;
        while (temp->getNext() != NULL)
        {
          temp = temp->getNext();
        }
        temp->setNext(node);
        cout << "Node Appended\n";
      }
    }
  }
  // 3- prepend node to the list
  void
  prependNode(Node *node)
  {
    if (nodeExist(node->getKey()) != NULL)
    {
      cout << "key already used by another node\n";
    }
    else
    {
      node->setNext(head);
      head = node;
      cout << "Node Prepended\n";
    }
  }
  // 4- insert a node after a particular node in the list
  void insertNodeAfter(int key, Node *node, int secondKey)
  {
    Node *temp = nodeExist(secondKey);
    if (temp == NULL)
      cout << "there is no node that has the key : " << secondKey << "\n";
    else
    {
      if (nodeExist(key) != NULL)
        cout << "key already used by another node\n";
      else
      {
        node->setNext(temp->getNext());
        temp->setNext(node);
        cout << "node inserted succefully\n";
      }
    }
  }
  // 5 delete node by unique key
  void deleteNode(int key)
  {
    if (head == NULL)
      cout << "Singly linked list already empty. Cant delete\n";
    else
    {
      if (head->getKey() == key)
      {
        head = head->getNext();
        cout << "Node unlinked from list\n";
      }
      else
      {
        Node *temp = NULL;
        Node *prevNode = head;
        Node *currentNode = head->getNext();
        while (currentNode != NULL)
        {
          if (currentNode->getKey() == key)
          {
            temp = currentNode;
            currentNode = NULL;
          }
          else
          {
            currentNode = currentNode->getNext();
            prevNode = prevNode->getNext();
          }
        }
        if (temp == NULL)
          cout << "node doesn't exist\n";
        else
        {
          prevNode->setNext(temp->getNext());
          cout << "node unlinked\n";
        }
      }
    }
  }
  // 6- Update node by key
  void updateNode(int key, int data)
  {
    Node *nodePtr = nodeExist(key);
    if (nodePtr != NULL)
    {
      nodePtr->setData(data);
      cout << "node updated succefully\n";
    }
    else
      cout << "node doesn't exist\n";
  }
  // 7- display linked list
  void display()
  {
    if (head == NULL)
    {
      cout << "Linked list empty\n";
    }
    else
    {
      Node *temp = head;
      while (temp != NULL)
      {
        cout << temp->getKey() << " --> " << temp->getData() << "\n";
        temp = temp->getNext();
      }
    }
  }
};
int main()
{
  SinglyLinkedList list;
  int key, data, secondKey, option;
  cout << "This is a live implementation of a linked list\n";
  do
  {
    cout << "Please choose a number between options - choose 0 to exit\n";
    cout << "[1] => appendNode()\n";
    cout << "[2] => prependNode()\n";
    cout << "[3] => insertNodeAfter()\n";
    cout << "[4] => deleteNodeByKey()\n";
    cout << "[5] => updateNodeByKey()\n";
    cout << "[6] => display()\n";
    cout << "[7] => Clear Terminal\n";
    cin >> option;
    Node *node = new Node();
    switch (option)
    {
    case 0:
      break;
    case 1:
      cout << "Append node operation\n";
      cout << "Enter the key of the node to be appended\n";
      cin >> key;
      cout << "Enter the data of the node to be appended\n";
      cin >> data;
      node->setKey(key);
      node->setData(data);
      list.appendNode(node);
      break;
    case 2:
      cout << "Prepend node operation\n";
      cout << "Enter the key of the node to be prepended\n";
      cin >> key;
      cout << "Enter the data of the node to be prepended\n";
      cin >> data;
      node->setKey(key);
      node->setData(data);
      list.prependNode(node);
      break;
    case 3:
      cout << "InsertNodeAfter() operation\n";
      cout << "Enter the key of the node to be inserted\n";
      cin >> key;
      cout << "Enter the data of the node to be inserted\n";
      cin >> data;
      cout << "Enter the the key of the node that you to insert this node after\n";
      cin >> secondKey;
      node->setKey(key);
      node->setData(data);
      list.insertNodeAfter(key, node, secondKey);
      break;
    case 4:
      cout << "DeleteNodeByKey() operation\n";
      cout << "Enter the key of the node you want to delete\n";
      cin >> key;
      list.deleteNode(key);
      break;
    case 5:
      cout << "UpdateNodeByKey() operation\n";
      cout << "Enter the key of the node you want to update\n";
      cin >> key;
      cout << "Enter the new data you want to update the node with\n";
      cin >> data;
      list.updateNode(key, data);
      break;
    case 6:
      cout << "DisplayList() operation\n";
      list.display();
      break;
    case 7:
      system("clear");
      break;
    default:
      cout << "Please enter a valid key\n";
    }
  } while (option != 0);
  return 0;
}
