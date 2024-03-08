#include<iostream>
using namespace std;

int swap(int *arr1, int *arr2)
{
    int temp;

    temp = *arr1;
    *arr1 = *arr2;
    *arr2 = temp;
}

int partition(int arr[], int low, int high)
{
    int piviot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(arr[j] < piviot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

void quicksort(int arr[], int low, int high)
{
    if(low < high)
    {
        int curr = partition(arr, low, high);

        quicksort(arr, low, curr - 1);
        quicksort(arr, curr + 1, high);
    }
}

void display(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << "    ";
    }
    cout <<endl;
}

int main()
{
    int n = 6;
    int arr[] = {3, 5, 2, 7, 9, 6};

    display(arr, n);

    quicksort(arr, 0, n-1);

    display(arr, n);
}