#include <bits/stdc++.h>

void bubbleSort(int* arr, int size)
{
    for(int i=0; i<size-1; i++)
    {
        for(int i=0; i<size-1; i++)
        {
            if(arr[i] > arr[i+1])
            {
                arr[i+1] += arr[i];
                arr[i] = arr[i+1] - arr[i];
                arr[i+1] -= arr[i]; 
            }
        }
        size--;
    }
}

int main(void)
{
    srand(0);
    int arr[10] = {};
    for(int i=0; i<sizeof(arr)/sizeof(int); i++)
        arr[i] = rand() % 26;
    std::cout << std::endl;
    
    for(int i=0; i<sizeof(arr)/sizeof(int); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    bubbleSort(arr, sizeof(arr)/sizeof(int));

    for(int i=0; i<sizeof(arr)/sizeof(int); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}
