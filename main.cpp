#include <bits/stdc++.h>

void maxHeapify(int* arr, int size, int nodeNum)
{
    int leftChild = 2*nodeNum + 1;
    int rightChild = 2*nodeNum + 2;
    int root = nodeNum;

    if(leftChild < size && arr[leftChild] > arr[root])
    {
        root = leftChild;
    }
    
    if(rightChild < size && arr[rightChild] > arr[root])
    {
        root = rightChild;
    }

    if(root == rightChild || root == leftChild)
    {
        std::swap(arr[root], arr[nodeNum]);
        maxHeapify(arr, size, root);
    }
}

void heapSort(int* arr, int size)
{
    for(int i = (size/2)-1; i>=0; i--)
        maxHeapify(arr, size, i);

    for(int i=size-1; i>0; i--)
    {
        std::swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

void histogramSort(int* arr, int size)
{
    std::map<int, int> buckets;
    for(int i=0; i<size; i++)
    {
        buckets[arr[i]]++;
    }

    int i = 0;
    for(auto it = buckets.begin(); it != buckets.end(); it++)
    {
        for(int y=i; y<i+it->second; y++)
        {
            arr[y] = it->first;
        }
        i += it->second; 
    }
}

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

void bubbleSort(int* arr, int size)
{
    for(int i=0; i<size-1; i++)
    {
        for(int j=0; j<size-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                arr[j+1] += arr[j];
                arr[j] = arr[j+1] - arr[j];
                arr[j+1] -= arr[j];
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

    quickSort(arr, -1, sizeof(arr)/sizeof(int) - 1);

    heapSort(arr, sizeof(arr)/sizeof(int));

    histogramSort(arr, sizeof(arr)/sizeof(int));

    RecursiveBubbleSort(arr, sizeof(arr)/sizeof(int));

    insertionSort(arr, sizeof(arr)/sizeof(int));

    mergeSort(arr, sizeof(arr)/sizeof(int), 1);

    bubbleSort(arr, sizeof(arr)/sizeof(int));

    for(int i=0; i<sizeof(arr)/sizeof(int); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}



