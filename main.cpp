#include <bits/stdc++.h>

void RecursiveBubbleSort(int* arr, int size)
{
    if(size == 1)
        return;

    for(int i=0; i<size-1; i++)
    {
        if(arr[i] > arr[i+1])
        {
            arr[i+1] += arr[i];
            arr[i] = arr[i+1] - arr[i];
            arr[i+1] -= arr[i];
        }
    }

    RecursiveBubbleSort(arr, --size);
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

    RecursiveBubbleSort(arr, sizeof(arr)/sizeof(int));

    for(int i=0; i<sizeof(arr)/sizeof(int); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}
