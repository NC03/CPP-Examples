/**
 * Linked List Example
 * 
 * @author NC03
 * @date November 20, 2020
 * @file
 * 
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cassert>

using namespace std;

class Node
{
public:
    Node() : Node(0)
    {
    }
    Node(const Node &node) : Node(0)
    {
        for (int i = 0; i < node.length(); i++)
        {
            append(node[i]);
        }
    }
    ~Node()
    {
        if (next != nullptr)
        {
            delete next;
        }
    }
    Node &operator=(const Node &rh)
    {
        if (this != &rh)
        {
            Node *temp = next;
            while (temp != nullptr)
            {
                Node *store = temp->next;
                delete temp;
                temp = store;
            }
            for (int i = 0; i < rh.length(); i++)
            {
                append(rh[i]);
            }
        }
    }

    void prepend(int v)
    {
        Node *newNode = new Node(v);
        newNode->next = next;
        next = newNode;
    }

    void append(int v)
    {
        Node *newNode = new Node(v);
        Node *current = this;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }

    int length() const
    {
        int len = 0;
        Node *nextPtr = next;
        while (nextPtr != nullptr)
        {
            len++;
            nextPtr = nextPtr->next;
        }
        return len;
    }

    int &operator[](int idx)
    {
        assert(idx < length());
        Node *nextPtr = next;
        for (int i = 0; i < idx; i++)
        {
            nextPtr = nextPtr->next;
        }
        return nextPtr->value;
    }
    int operator[](int idx) const
    {
        assert(idx < length());
        Node *nextPtr = next;
        for (int i = 0; i < idx; i++)
        {
            nextPtr = nextPtr->next;
        }
        return nextPtr->value;
    }

    void insert(int idx, int v)
    {
        Node *newNode = new Node(v);
        Node *current = this;
        for (int i = 0; i < idx; i++)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    friend ostream &operator<<(ostream &out, const Node &root);

private:
    Node(int v) : value(v), next(nullptr)
    {
    }

    int value;
    Node *next;
};

ostream &operator<<(ostream &out, const Node &root)
{
    Node *next = root.next;
    while (next != nullptr)
    {
        out << next->value << " ";
        next = next->next;
    }
    return out;
}

int main()
{
    cout << "linkedList.cpp" << endl;

    Node n;
    n.prepend(4);
    n.prepend(3);
    n.prepend(2);
    n.prepend(1);
    n.insert(2, 5);
    n.append(-1);

    cout << n << endl;
    for (int i = 0; i < n.length() - 1; i++)
    {
        cout << n[i] << ",";
    }
    cout << n[n.length() - 1] << endl;

    return 0;
}
