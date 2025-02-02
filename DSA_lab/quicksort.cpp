#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
// quick sort breaks the array and then sort them
// first we make a break function according to pivot
int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}
 
void quickSort(int arr[], int start, int end)
{
    // base case
    if (start >= end)
        return;
    // partitioning the array
    int p = partition(arr, start, end);
    // Sorting the left part
    quickSort(arr, start, p - 1);
    // Sorting the right part
    quickSort(arr, p + 1, end);
}

void printing_sorted_array(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        cout << "[" << i << "]: " << arr[i] << endl;
    }
}

int main()
{
    int len = 7;
    int array[len] = {8, 5, 9, 7, 3, 2, 6};
    quickSort(array, 0, len - 1);
    printing_sorted_array(array,len);
    return 0;
}