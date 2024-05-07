#include <bits/stdc++.h>
using namespace std;

int linear_search(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {2, 6, 3, 0, 9};
    int n = sizeof(arr) / sizeof(int);
    int k = linear_search(arr, n, arr[1]);
    cout << "at index : " << k;
    return 0;
}