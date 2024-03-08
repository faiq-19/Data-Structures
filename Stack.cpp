#include<iostream>
using namespace std;

int n = 10;

class stack
{
    int *arr;
    int top;

    public:
    stack()
    {
        arr = new int[n];
        top = -1;
    }
    void push(int data)
    {
        if(top-1 == n)
        {
            cout << "Stack Overflow" << endl;
            return;
        }

        top++;
        arr[top] = data;
    }
    void pop()
    {
        if(top == -1)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
    }
};

int main()
{

}