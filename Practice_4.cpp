#include<iostream>
using namespace std;

void merge_sort(int arr[], int l, int h, int mid)
{
    int n1 = mid - l + 1;
    int n2 = h - mid;
    int i, j, k;
    int *left = new int [n1];
    int *right = new int [n2];

    for(i = 0; i < n1; i++)
    {
        left[i] = arr[l + i];
    }
    for(j = 0; j < n2; j++)
    {
        right[j] = arr[mid + 1 + j];
    }

    i = 0; j = 0; k = l;

    while(i < n1 && j < n2)
    {
        if(left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while(i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void merge(int arr[], int l, int h)
{
    if(l < h)
    {
        int mid = (l + h) / 2;

        merge(arr, l, mid);
        merge(arr, mid+1, h);
        merge_sort(arr, l, h, mid);
    }
}

int main()
{
    int arr[10] = {3, 2, 6, 8, 29, 35, 7, 9, 10, 11};

    merge(arr, 0, 9);

    for(int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
}