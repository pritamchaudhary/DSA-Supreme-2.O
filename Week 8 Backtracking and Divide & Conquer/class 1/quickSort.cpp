// gfg -> Quick Sort

#include<iostream>
using namespace std;

class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low >= high){
            return;
        }
        int pivot = high;
        int i = low - 1;
        int j = low;
        
        while(j < pivot){
            if(arr[j] < arr[pivot]){
                i++;
                swap(arr[i], arr[j]);
            }
            j++;
        }
        i++;
        swap(arr[i], arr[pivot]);
        quickSort(arr, low, i-1);
        quickSort(arr, i+1, high);
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
    //   WON'T USE IT
    }
};