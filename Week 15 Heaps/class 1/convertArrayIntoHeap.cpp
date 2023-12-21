// convert array into heap

#include <iostream>
using namespace std;

class Heap
{
public:
    int *arr;
    int size;
    int capacity;

    Heap(int capacity)
    {
        this->arr = new int[capacity];
        this->size = 0;
        this->capacity = capacity;
    }

    void insert(int val)
    {
        if (size == capacity)
        {
            cout << "Heap Overflow" << endl;
            return;
        }
        // size increase
        size++;
        int index = size;
        arr[index] = val;

        // take the val to the correct position
        while (index > 1)
        {
            int parentIndex = index / 2;
            if (arr[index] > arr[parentIndex])
            {
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }


    }
    void printHeap()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
    }

    int deleteFromHeap(){
        int answer = arr[1];
        // replacement
        arr[1] = arr[size];
        // delete last element from it's original position
        size--;

        int index = 1;
        while(index < size){
            int leftIndex = 2 * index;
            int rightIndex = 2 * index + 1;

            // find out who is bigger
            int largestElementIndex = index;
            // check left child
            if(leftIndex <= size && arr[largestElementIndex] < arr[leftIndex]){
                largestElementIndex = leftIndex;
            }
            if(rightIndex <= size && arr[largestElementIndex] < arr[rightIndex]){
                largestElementIndex = rightIndex;
            }
            // no change
            if(index == largestElementIndex){
                break;
            }
            else{
                swap(arr[index], arr[largestElementIndex]);
                index = largestElementIndex;
            }
        }
        return answer;
    }
};

void heapify(int *arr, int n, int index){
    int leftIndex = 2 * index;
    int rightIndex = 2 * index + 1;
    int largestElementIndex = index;

    // max among 3 
    if(leftIndex <= n && arr[leftIndex] > arr[largestElementIndex]){
        largestElementIndex = leftIndex;
    }
    if(rightIndex <= n && arr[rightIndex] > arr[largestElementIndex]){
        largestElementIndex = rightIndex;
    }
    // after these 2 conditions largestElementIndex will be pointing towards largest element among 3
    if(index != largestElementIndex){
        swap(arr[index], arr[largestElementIndex]);
        // recursion call
        index = largestElementIndex;
        heapify(arr, n, index);
    }
}

void buildHeap(int arr[], int n){
    for(int index = n/2; index > 0; index--){
        heapify(arr, n, index);
    }
}

int main()
{
    int arr[] = {-1, 5, 10, 15, 20, 25, 12};
    int n = 6;
    buildHeap(arr, n);
    cout<<"printing heap: "<<endl;
    for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    

    return 0;
}