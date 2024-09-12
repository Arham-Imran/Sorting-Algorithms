#include <bits/stdc++.h>

void mergeTwoSubArrays(int* arr, int elementSize, int start, int size)
{
    int tempArr[2*elementSize] = {};
    int i = start;
    int j = start + elementSize;
    for(int z=0; z<2*elementSize; z++)
    {
        if((j >= size || j >= (start + 2*elementSize))  && (i >= start + elementSize)) // checking if both subarrays have been completely traversed
        {
            break;
        }
        else if((j >= size || j >= (start + 2*elementSize)) && i < start + elementSize) // checking if 2nd subarray's limit has been hit and not first's
        {
            tempArr[z] = arr[i];
            i++;
            continue;
        }
        else if(i >= (start + elementSize) && j < size && j < (start + 2*elementSize)) // checking if 1st subarray's limit has been hit and not second's
        {
            tempArr[z] = arr[j];
            j++;
            continue;
        }

        if(arr[i] < arr[j])
        {
            tempArr[z] = arr[i];
            i++;
        }
        else if(arr[j] <= arr[i])
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
