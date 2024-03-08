#include<iostream>
using namespace std;

// //check if it is safe for the array to move i.e check the row and column
// bool isSafe(int **arr, int x, int y, int n)
// {
//     if(x < n && y < n && arr[x][y] == 1)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }
// bool ratInMaze(int **arr, int x, int y, int n, int **sol_arr)
// {
//     if(x == n - 1 && y == n - 1)
//     {
//         sol_arr[x][y] = 1;
//         return true;
//     }
//     if(isSafe(arr, x, y, n))
//     {
//         sol_arr[x][y] = 1;

//         //this one is for checking our next index and placing the value
//         if(ratInMaze(arr, x + 1, y, n, sol_arr))
//         {
//             return true;
//         }
//         if(ratInMaze(arr, x, y + 1, n, sol_arr))
//         {
//             return true;
//         }
//         //Now Backtracking
//         sol_arr[x][y] = 0;

//         return false;
//     }
//     return false;
// }
// int main()
// {
//     int n = 4;

//     int **arr = new int*[4];

//     for(int i = 0; i < 4; i++)
//     {
//         arr[i] = new int[4];
//     }
//     for(int i = 0; i < 4; i++)
//     {
//         for(int j = 0; j < 4; j++)
//         {
//             cin >> arr[i][j];
//         }
//     }

//     int **sol_arr = new int*[4];

//     for(int i = 0; i < 4; i++)
//     {
//         sol_arr[i] = new int[4];
//     }
//     for(int i = 0; i < 4; i++)
//     {
//         for(int j = 0; j < 4; j++)
//         {
//             sol_arr[i][j] = 0;
//         }
//     }

//     if(ratInMaze(arr, 0, 0, 4, sol_arr))
//     {
//         for(int i = 0; i < 4; i++)
//         {
//             for(int j = 0; j < 4; j++)
//             {
//                 cout << sol_arr[i][j] << "  ";
//             }cout << endl;
//         }
//     }
// }

// // 1 0 0 0
// // 1 1 0 1
// // 0 1 1 0
// // 1 1 1 1

//Nigga Queen

bool isSafe(int **arr, int row, int col)
{
    int x = row;
    int y = col;

    for(x = 0; x < row; x++)
    {
        if(arr[x][col] == 1)
        {
            return false;
        }
    }
    while(row >= 0 && col >= 0)
    {
        if(arr[x][y] == 1)
        {
            return false;
        }
        row--;
        col--;
    }
    return true;
}

bool N_Queen(int **arr, int row, int n)
{
    if(row > n)
    {
        return true;
    }
    for(int y = 0; y < n; y++)
    {
        if(isSafe(arr, row, y))
        {
            arr[row][y] = 1;

            if(N_Queen(arr, row+1, n))
            {
                return true;
            }
            arr[row][y] = 0;
        }
    }
    return false;
}

int main()
{

}