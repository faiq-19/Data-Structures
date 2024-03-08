#include<iostream>
using namespace std;

class NODE
{
    public:
    int data;
    NODE *next;

    NODE(int data)
    {
        next = NULL;
        this -> data = data;
    }
    NODE()
    {
        next = NULL;
        data = 0;
    }
};

class List
{
    public:
    NODE *head;

    List(NODE *obj)
    {
        head = obj;
    }
    List()
    {
        head = NULL;
    }

    void addtotail(int data)
    {
        NODE *N = new NODE(data);
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
    int total_nodes()
    {
        int count = 0;
        NODE *temp = head;

        while(temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    void Bin_Scearch(int key)
    {
        int high = total_nodes();
        int low = 1;
        int mid;

        //find mid node and do the rest of the steps instead of incrmenting low and hight you will increment the high node and low node 
        //wtr to the mid
    }
    void Sort()
    {
        NODE *curr = head;
        NODE *index;
        int temp;

        while(curr != NULL)
        {
            index = curr->next;

            while(index != NULL)
            {
                if(curr->data > index->data)
                {
                    temp = curr->data;
                    curr->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            curr = curr->next;
        }
    }
    void display()
    {
        NODE *temp = head;

        cout << "NULL";
        while(temp != NULL)
        {
            cout << "->" << temp->data;
            temp = temp->next;
        }
        cout << "->NULL" << endl;
    }
};

int main()
{
    NODE *head = NULL;
    List l(head);

    l.addtotail(4);
    l.addtotail(53);
    l.addtotail(32);
    l.addtotail(1);
    l.addtotail(99);
    l.addtotail(46);

    l.display();

    l.Sort();

    l.display();
}