#include <bits/stdc++.h>

void quickSort(int* arr, int low, int high)
{
    if((high - low) <= 1)
        return;

    int pivot = arr[high];
    for(int i=low+1; i<=high; i++)
    {
        if(arr[i] < pivot)
        {
            int temp = arr[++low];
            arr[low] = arr[i];
            arr[i] = temp;
        }
    }
    int temp = arr[++low];
    arr[low] = pivot;
    arr[high] = temp;

    quickSort(arr, -1, --low);
    quickSort(arr, low+1, high);
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

    quickSort(arr, -1, sizeof(arr)/sizeof(int) - 1);

    for(int i=0; i<sizeof(arr)/sizeof(int); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}
