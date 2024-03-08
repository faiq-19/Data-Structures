#include<iostream>
using namespace std;

class HashNode
{
    public:
    HashNode *next;
    string data;

    HashNode()
    {
        next = NULL;
        data = '0';
    }
    HashNode(string data)
    {
        next = NULL;
        this->data = data;
    }
};

class Hash
{  
    public:
    HashNode **h;
    int size;

    Hash(int size)
    {  
        this->size = size;

        h = new HashNode * [size];

        for(int i = 0; i < size; i++)
        {
            h[i] = NULL;
        }
    }
    int hashFunction(int key)
    {
        return key % size;
    }
    int find_key(string data)
    {
        int sum = 0;
        int sum_of_Id = 0;
        int result = 0;
        int Id = 214665;

        for(int i = 0; i < data.length(); i++)
        {
            sum = sum + (int)data[i];
        }
        while(Id != 0)
        {
            result = Id % 10;
            sum_of_Id = result + sum_of_Id;
            Id = Id / 10;
        }

        sum = sum + sum_of_Id;

        return sum;
    }
    void addValue(string data)
    {
        int value = find_key(data);

        int key = hashFunction(value);

        if(h[key] == NULL)
        {
            h[key] = new HashNode(data);
        }
        else if(h[key] != NULL)
        {
            cout << "Worked" << endl;

            HashNode *temp = h[key];
            HashNode *prev = NULL;

            while(temp != NULL)
            {
                prev = temp;
                temp = temp->next;
            }
            if(temp == NULL)
            {
                temp = new HashNode(data);

                if(prev == NULL)
                {
                    h[key] = temp;
                }
                else
                {
                    prev->next = temp;
                }
            }
        }
    }
    void display()
    {
        for(int i = 0; i < size; i++)
        {
            if(h[i] == NULL)
            {
                cout << "-----|---------" << endl;
            }
            else
            {
                cout << i << ".   |   " << h[i]->data << "->";

                HashNode *temp = h[i];

                while(temp->next != NULL)
                {
                    temp = temp->next;
                    cout << temp->data << "->";
                }
                cout << "NULL" << endl;
            }
        }
    }
};

int main()
{
    Hash h(20);

    string arr[10] = {"Kindness", "Politeness" , "Understandable", "Empathy", "Knowledge", "Gratitude", "Patience", "Righteous", "Appreciate","Easy"};

    for(int i = 0; i < 10; i++)
    {
        h.addValue(arr[i]);
    }
    h.display();
}