#include <bits/stdc++.h>

void mergeTwoSubArrays(int* arr, int elementSize, int start, int size)
{
    int tempArr[2*elementSize] = {};
    int i = start;
    int j = start + elementSize;
    for(int z=0; z<2*elementSize; z++)
    {
        if(j >= size && i < start + elementSize)
        {
            tempArr[z] = arr[i];
            i++;
            continue;
        }
        else if(j >= size && i >= start + elementSize)
        {
            break;
        }
        if(arr[i] < arr[j] && i < (start + elementSize))
        {
            tempArr[z] = arr[i];
            i++;
        }
        else if(arr[j] <= arr[i] && j < (start + 2*elementSize) && j < size)
        {
            tempArr[z] = arr[j];
            j++;
        }
        else if(j >= (start + 2*elementSize))
        {
            tempArr[z] = arr[i];
            i++;
        }
        else if(i >= (start + elementSize) && j < size)
        {
            tempArr[z] = arr[j];
            j++;
        }
    }

    int y = 0;
    for(int z=start; z<((start+(2*elementSize))>size? size : (start+(2*elementSize))); z++)
    {
        arr[z] = tempArr[y];
        y++;
    }
}

void mergeSort(int* arr, int size, int elementSize)
{
    if(elementSize >= size)
        return;
    for(int i=0; i<size; i+=2*elementSize)
    {
        mergeTwoSubArrays(arr, elementSize, i, size);
    }
    mergeSort(arr, size, elementSize*2);
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

    mergeSort(arr, sizeof(arr)/sizeof(int), 1);

    for(int i=0; i<sizeof(arr)/sizeof(int); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}
