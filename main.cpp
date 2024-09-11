#include <bits/stdc++.h>

void insertionSort(int* arr, int size)
{
    int curr, move;
    for(int i=1; i<size; i++)
    {
        move = curr = arr[i];
        for(int j=0; j<i; j++)
        {
            if(curr<arr[j])
            {
                move = arr[j];
                arr[j] = curr;
                curr = move;
            }
            
            if(j == i-1)
            {
                arr[j+1] = move;
            }
        }
    }
}

int main(void)
{
    srand(time(0));
    int arr[10] = {};
    for(int i=0; i<sizeof(arr)/sizeof(int); i++)
        arr[i] = rand() % 26;
    std::cout << std::endl;
    
    for(int i=0; i<sizeof(arr)/sizeof(int); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    insertionSort(arr, sizeof(arr)/sizeof(int));

    for(int i=0; i<sizeof(arr)/sizeof(int); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}
