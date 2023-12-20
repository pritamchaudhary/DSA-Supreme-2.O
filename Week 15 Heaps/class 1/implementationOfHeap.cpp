// implementation of heap

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

int main()
{
    Heap h(20);
    // insertion
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(11);
    h.insert(6);

    cout << "Printing the content of Heap: " << endl;
    h.printHeap();
    cout<<endl;

    int ans = h.deleteFromHeap();
    cout<<"Answer: "<<ans<<endl;

    return 0;
}