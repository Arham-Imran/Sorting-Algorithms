#include <bits/stdc++.h>

void maxHeapify(int* arr, int size, int nodeNum)
{
    int leftChild = 2*nodeNum + 1;
    int rightChild = 2*nodeNum + 2;

    if(leftChild < size && arr[leftChild] > arr[nodeNum] && (rightChild >= size || (arr[leftChild] >= arr[rightChild])))
    {
        std::swap(arr[leftChild], arr[nodeNum]);
        nodeNum = leftChild;
    }
    else if(rightChild < size && arr[rightChild] > arr[nodeNum])
    {
        std::swap(arr[rightChild], arr[nodeNum]);
        nodeNum = rightChild;
    }

    if(nodeNum == rightChild || nodeNum == leftChild)
        maxHeapify(arr, size, nodeNum);

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

    for(int i=0; i<sizeof(arr)/sizeof(int); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}
