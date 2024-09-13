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


    heapSort(arr, sizeof(arr)/sizeof(int));

    histogramSort(arr, sizeof(arr)/sizeof(int));

    for(int i=0; i<sizeof(arr)/sizeof(int); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}
