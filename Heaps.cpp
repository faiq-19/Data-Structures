#include<iostream>
using namespace std;

class Heap
{
    int *arr;
    int max_size;
    int capacity;

    public:
    Heap(int size)
    {
        max_size = size;
        arr = new int [max_size];
        capacity = -1;
    }
    int leftchild(int i)
    {
        return ((2 * i) + 1);
    }
    int rightchild(int i)
    {
        return ((2 * i) + 2);
    }
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    void shiftup(int i)
    {
        while(i > 0 && arr[parent(i)] < arr[i])
        {
            swap(arr[parent(i)], arr[i]);
            
            i = parent(i);
        }
    }
    void shiftdown(int i)
    {   
        int maxindex = i;
        int l = leftchild(i);

        if(l <= capacity && arr[l] > arr[maxindex])
        {
            maxindex = l;
        }        

        int r = rightchild(i);

        if(r <= capacity && arr[r] > arr[maxindex])
        {
            maxindex = r;
        }
        
        if(i != maxindex)
        {
            swap(arr[i], arr[maxindex]);
            shiftdown(maxindex);
        }
    }
    int extractMax()
    {
        int result = arr[0];

        arr[0] = arr[capacity];

        capacity--;

        shiftdown(0);

        return result;
    }
    void insert(int data)
    {
        if(capacity == max_size)
        {
            cout << "Heap Overflow" << endl;
            return;
        }

        capacity++;

        arr[capacity] = data;

        shiftup(capacity);
    }
    int getmax()
    {
        return arr[0];
    }
    void deletenode(int i)
    {
        arr[i] = getmax() + 1;

        shiftup(i);
        extractMax();
    }
    void display()
    {
        cout << endl;

        for(int i = 0; i <= capacity; i++)
        {
            cout << arr[i] << "  ";
        }
        cout << endl;
    }
};

int main()
{
    Heap H(10);

    H.insert(45);
    H.insert(50);
    H.insert(33);
    H.insert(56);
    H.insert(86);
    H.insert(33);

    H.display();

    //cout << H.extractMax();

    //H.display();

    H.deletenode(2);

    H.display();
}