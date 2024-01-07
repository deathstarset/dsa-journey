#include <iostream>
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

  // operations

  // 1- checking if a node exist
  Node *nodeExist(int key)
  {
    if (head == nullptr)
    {
      return nullptr;
    }
    else
    {
      if (head->getKey() == key)
      {
        return head;
      }
      else
      {
        Node *temp = head->getNext();
        while (temp != head)
        {
          if (temp->getKey() == key)
          {
            return temp;
          }
          temp = temp->getNext();
        }
      }
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
      {
        cout << "No node exist with the key value : " << key << ".\n";
      }
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
        Node *temp = head;
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
      else if (temp->getNext() == head)
      {
        Node *prevNode = head;
        while (prevNode->getNext() != temp)
        {
          prevNode = prevNode->getNext();
        }
        prevNode->setNext(head);
        temp->setNext(nullptr);
        cout << "Node Deleted At Last\n";
      }
      else
      {
        Node *prevNode = head;
        while (prevNode->getNext() != temp)
        {
          prevNode = prevNode->getNext();
        }
        prevNode->setNext(temp->getNext());
        temp->setNext(nullptr);
        cout << "Node Deleted In Between\n";
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
      Node *temp = head->getNext();
      if (temp == head)
      {
        cout << "Key -> " << temp->getKey() << " --- "
             << "Data -> " << temp->getData() << "\n";
      }
      else
      {
        cout << "Key -> " << head->getKey() << " --- "
             << "Data -> " << head->getData() << "\n";
        while (temp != head)
        {
          cout << "Key -> " << temp->getKey() << " --- "
               << "Data -> " << temp->getData() << "\n";
          temp = temp->getNext();
        }
      }
    }
  }
}

;
int main()
{
  Node n1(1, 10);
  Node n2(2, 20);
  Node n3(3, 30);
  Node n4(4, 40);
  Node n5(5, 50);
  CircularLinkedList list;
  list.appendNode(&n1);
  list.appendNode(&n2);
  list.appendNode(&n3);
  list.appendNode(&n4);
  list.deleteNode(1);
  list.updateNode(2, 44);
  list.display();
  return 0;
}