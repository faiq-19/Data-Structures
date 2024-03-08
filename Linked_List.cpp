#include<iostream>
using namespace std;

class NODE
{
    public:
    int data;
    int key;
    NODE *next;

    NODE()
    {
        key = 0;
        data = 0;
        next = NULL;
    }
    NODE(int key, int data)
    {
        this->data = data;
        this->key = key;
        next = NULL;
    }
    ~NODE();
};

void insert_at_tail(NODE* &head, int key, int value)
{
    NODE *N = new NODE(key, value);
    NODE *temp = head;

    if(head == NULL)
    {
        head = N;
        return;
    }
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = N;
}

void add_to_head(NODE* &head, int key, int value)
{
    NODE *N = new NODE(key, value);

    N->next = head;
    head = N;
}

void scearch(NODE* &head, int key)
{
    NODE* temp = head;

    while(temp->key != key)
    {
        temp = temp->next;
    }
    if(key == temp->key)
    {
        cout << "Key:" << temp->key << "   Data:" << temp->data << endl;
    }
    else
    {
        cout << "List Not Found" << endl;
    }
}

void display(NODE *head)
{
    NODE *temp = head;

    do
    {
        cout << "Key:" << temp->key << "   Data:" << temp->data << endl;
        temp = temp->next;
    } while(temp->next != NULL);

    cout << "Key:" << temp->key << "   Data:" << temp->data << endl;
}

NODE* reverse_list(NODE* &head)
{
    NODE *curr_node = head;
    NODE *prev_node = NULL;
    NODE *next_node;

    while(curr_node != NULL)
    {
        next_node = curr_node->next;
        curr_node->next = prev_node;

        //Iterating

        prev_node = curr_node;
        curr_node = next_node;
    }

    return prev_node;
}

NODE* reverse_recursion(NODE* &head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    NODE *N = reverse_recursion(head->next);
    
    head->next->next = head;
    head->next = NULL;
    
    return N;
}

void add_at_key(NODE* &head, int key, int data)
{
    NODE *New = new NODE(key, data);
    NODE *temp = head;

    while(temp->key != key)
    {
        temp = temp->next;
    }
    New->next = temp->next;
    temp->next = New;

    head = temp;
}

int main()
{
    NODE *head = NULL;

    insert_at_tail(head, 0, 54);
    insert_at_tail(head, 1, 73);
    insert_at_tail(head, 2, 89);
    insert_at_tail(head, 3, 987);
    insert_at_tail(head, 4, 7);

    display(head);

    cout << endl;

    NODE *newHead = reverse_recursion(head);

    display(newHead);

    cout << endl;

    insert_at_tail(head, 3, 999);

    display(head);
}