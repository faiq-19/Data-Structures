#include <iostream>
using namespace std;

int arr[10];
int size = 10;
int q1_front = 0, q1_last = -1, q2_front = size / 2, q2_last = q2_front;

int push_Q1(int data)
{
    if(q1_last == size / 2)
    {
        return 0;
    }
    q1_last++;
    arr[q1_last] = data;
}

int push_Q2(int data)
{
    if(q2_last == size)
    {
        return 0;
    }
    q2_last++;
    arr[q2_last] = data;
}


class Stack
{
public:
    int *stack;
    int size;
    int s1;

    Stack(int size)
    {
        this->size = size;
        stack = new int[size];
        s1 = -1;
    }
    void push(int data)
    {
        if (s1 == size)
        {
            cout << "Stack Overflow";
            return;
        }
        s1++;
        stack[s1] = data;
    }
    void pop()
    {
        if (s1 == -1)
        {
            cout << "Stack Underflow";
            return;
        }
        s1--;
    }
    int Last()
    {
        return stack[s1];
    }
    void display()
    {
        cout << endl;
        for(int i = 0; i <= s1; i++)
        {
            cout << stack[i] << "|";
        }
        cout << endl;
    }
};

int compare(int a, int b)
{
    if (a > b)
    {
        return 1;
    }
    else if (a < b)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

void Merge(Stack s1, Stack s2)
{
    Stack t_s1(s1.size);
    Stack t_s2(s2.size);
    Stack m_s(s1.size + s2.size);

    s1.display();
    s2.display();

    int first = s1.s1;
    int second = s2.s1;

    for (int i = 0; i <= first; i++)
    {
        t_s1.push(s1.Last());
        s1.pop();
    }
    for (int i = 0; i <= second; i++)
    {
        t_s2.push(s2.Last());
        s2.pop();
    }

    t_s1.display();
    t_s2.display();

    int last = t_s1.s1 + t_s2.s1;

    for (int i = 0; i <= last; i++)
    {
        if(compare(t_s1.Last(), t_s2.Last()) == 1)
        {
            m_s.push(t_s2.Last());
            m_s.push(t_s1.Last());

            if(i != last / 2);
            {
                t_s1.pop();
                t_s2.pop();
            }
        }
        else if(compare(t_s1.Last(), t_s2.Last()) == -1)
        {
            m_s.push(t_s1.Last());
            m_s.push(t_s2.Last());

            if(i != last / 2);
            {
                t_s1.pop();
                t_s2.pop();
            }
        }
        else
        {
            m_s.push(t_s1.Last());
            m_s.push(t_s2.Last());

            if(i != last / 2);
            {
                t_s1.pop();
                t_s2.pop();
            }
        }
    }

    m_s.display();
}

class Node
{
public:
    Node *next;
    Node *left;
    Node *right;
    int data;

    Node()
    {
        next = NULL;
        data = 0;
        left = NULL;
        right = NULL;
    }
    Node(int data)
    {
        next = NULL;
        this->data = data;
        right = NULL;
        left = NULL;
    }
};

class BST
{
    Node *root;

    BST(Node *&obj)
    {
        root = obj;
    }
    BST()
    {
        root = NULL;
    }
    Node *findAncestor(Node *root, Node *n1, Node *n2)
    {
        if(root->data > n1->data && root->data < n2->data || root->data < n1->data && root->data > n2->data)
        {
            return root;
        }
        if(root->data > n1->data && root->data > n2->data)
        {
            findAncestor(root->left, n1, n2);
        }
        else if(root->data < n1->data && root->data < n2->data)
        {
            findAncestor(root->right, n1, n2);
        }
    }
    void insert(Node *root, int data)
    {
        if(root == NULL)
        {
            root = new Node (data);
            return;
        }
        if(root->data > data)
        {
            insert(root->left, data);
        }
        insert(root->right, data);
    }
};

class List
{
public:
    Node *head;

    List()
    {
        head = NULL;
    }
    void insert(int data)
    {
        if (head == NULL)
        {
            head = new Node(data);
            return;
        }

        Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = new Node(data);
    }
    void display()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    Node *ReturnLast()
    {
        Node *temp = head;
        Node *prev = NULL;

        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL;

        return temp;
    }
};

int main()
{
    int arr[10] = {2, 4, 3, 6, 2, 8, 9, 10, 44, 19};

    for (int i = 0; i < 10; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (arr[i] == arr[j])
            {
                cout << "Not Unique" << endl;
                break;
            }
        }
    }
    List l;

    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);
    l.insert(6);

    l.display();

    Node *node = l.ReturnLast();
    cout << endl
         << node->data << endl;

    l.display();

    cout << endl << endl;

    Stack s1(10);

    s1.push(1);
    s1.push(3);
    s1.push(7);
    s1.push(9);
    s1.push(10);

    Stack s2(10);

    s2.push(2);
    s2.push(4);
    s2.push(5);
    s2.push(6);
    s2.push(8);

    //Merge(s1, s2);
}