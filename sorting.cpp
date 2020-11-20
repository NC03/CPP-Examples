/**
 * Sorting Example
 * 
 * @author NC03
 * @date November 19, 2020
 * @file
 * 
 */
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
 * Enumeration of sorting algorithms
 * 
 */
enum class SortingAlgorithm
{
    BUBBLE_SORT,
    SELECTION_SORT,
    DEFAULT
};

void swap(int &a, int &b);
void print(const int arr[], const int size);
void sort(int arr[], const int size, const SortingAlgorithm algorithm = SortingAlgorithm::DEFAULT);

int main()
{
    cout << "sorting.cpp" << endl;
    srand(time(0));

    const int SIZE = 50;
    const int MAX = 100;
    int *arr = new int[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % MAX;
    }

    print(arr, SIZE);
    sort(arr, SIZE);
    cout << endl;
    print(arr, SIZE);

    delete[] arr;
    return 0;
}

/**
 * Print Array
 * 
 * 
 * @param arr The array to print
 * @param size The number of elements in the array
 */
void print(const int arr[], const int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        cout << arr[i] << " ";
    }
    if (size > 0)
    {
        cout << arr[size - 1] << endl;
    }
}

/**
 * Swaps Variables
 * 
 * @param a The reference to the first value to swap
 * @param b The reference to the second value to swap
 * 
 */
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

/**
 * Sorts the given array using the selection sort algorithm
 * 
 * @param arr The array to sort
 * @param size The number of elements in the array
 * 
 */
void selectionSort(int arr[], int size)
{
    for (int startIndex = 0; startIndex < size - 1; startIndex++)
    {
        int min = arr[startIndex];
        int swapIndex = startIndex;
        for (int j = startIndex + 1; j < size; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                swapIndex = j;
            }
        }
        swap(arr[startIndex], arr[swapIndex]);
    }
}

/**
 * Sorts the given array using the bubble sort algorithm
 * 
 * @param arr The array to sort
 * @param size The number of elements in the array
 * 
 */
void bubbleSort(int arr[], int size)
{
    for (int endIndex = size - 1; endIndex >= 1; endIndex--)
    {
        for (int j = 0; j < endIndex; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

/**
 * Sorts the given array using the specified algorithm
 * 
 * @param arr The array to sort
 * @param size The number of elements in the array
 * @param algorithm The algorithm to use
 * 
 */
void sort(int arr[], int size, const SortingAlgorithm algorithm)
{
    switch (algorithm)
    {
    case SortingAlgorithm::BUBBLE_SORT:
        bubbleSort(arr, size);
        break;
    case SortingAlgorithm::SELECTION_SORT:
        selectionSort(arr, size);
        break;
    default:
        bubbleSort(arr, size);
        break;
    }
}
