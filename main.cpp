#include <bits/stdc++.h>

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

    histogramSort(arr, sizeof(arr)/sizeof(int));

    for(int i=0; i<sizeof(arr)/sizeof(int); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}
