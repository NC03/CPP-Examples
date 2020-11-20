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
    MERGE_SORT,
    INSERTION_SORT,
    QUICK_SORT,
    DEFAULT
};

void swap(int &a, int &b);
void print(const int arr[], const int size);
void sort(int arr[], const int size, const SortingAlgorithm algorithm = SortingAlgorithm::DEFAULT);
ostream &operator<<(ostream &out, const SortingAlgorithm algorithm);

int main()
{
    cout << "sorting.cpp" << endl;

    srand(time(0));
    const int SIZE = 50;
    const int MAX = 200;
    const SortingAlgorithm algorithm = SortingAlgorithm::DEFAULT;

    int *arr = new int[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % MAX;
    }

    print(arr, SIZE);
    cout << algorithm << endl;
    sort(arr, SIZE, algorithm);
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
 * Sorts the given array using the merge sort algorithm
 * 
 * @param arr The array to sort
 * @param size The number of elements in the array
 * 
 */
void mergeSort(int arr[], int size)
{
    if (size <= 1)
    {
        return;
    }
    else
    {
        int size1 = size / 2, size2 = size - size1;
        int *arr1 = new int[size1], *arr2 = new int[size2];
        for (int i = 0; i < size; i++)
        {
            if (i < size1)
            {
                arr1[i] = arr[i];
            }
            else
            {
                arr2[i - size1] = arr[i];
            }
        }
        mergeSort(arr1, size1);
        mergeSort(arr2, size2);
        int index1 = 0, index2 = 0;
        for (int i = 0; i < size; i++)
        {
            if (index1 >= size1)
            {
                arr[i] = arr2[index2];
                index2++;
            }
            else if (index2 >= size2)
            {
                arr[i] = arr1[index1];
                index1++;
            }
            else if (arr1[index1] < arr2[index2])
            {
                arr[i] = arr1[index1];
                index1++;
            }
            else
            {
                arr[i] = arr2[index2];
                index2++;
            }
        }
        delete[] arr1;
        delete[] arr2;
    }
}

void insert(int arr[], int end, int index)
{
    int temp = arr[end];
    for (int i = end; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = temp;
}

/**
 * Sorts the given array using the insertion sort algorithm
 * 
 * @param arr The array to sort
 * @param size The number of elements in the array
 * 
 */
void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] <= arr[j])
            {
                insert(arr, i, j);
                break;
            }
        }
    }
}

/**
 * Sorts the given array using the quick sort algorithm
 * 
 * @param arr The array to sort
 * @param size The number of elements in the array
 * 
 */
void quickSort(int arr[], int size)
{
    if (size <= 1)
    {
        return;
    }
    int compIdx = size/2;
    int comp = arr[compIdx];
    int *arr1 = new int[size], *arr2 = new int[size], idx1 = 0, idx2 = 0;
    for (int i = 0; i < size; i++)
    {
        if (i == compIdx)
        {
            continue;
        }
        else if (arr[i] <= comp)
        {
            arr1[idx1] = arr[i];
            idx1++;
        }
        else
        {
            arr2[idx2] = arr[i];
            idx2++;
        }
    }

    quickSort(arr1, idx1);
    quickSort(arr2, idx2);

    for (int i = 0; i < size; i++)
    {
        if (i == idx1)
        {
            arr[i] = comp;
        }
        else if (i < idx1)
        {
            arr[i] = arr1[i];
        }
        else
        {
            arr[i] = arr2[i - idx1 - 1];
        }
    }

    delete[] arr1;
    delete[] arr2;
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
    case SortingAlgorithm::MERGE_SORT:
        mergeSort(arr, size);
        break;
    case SortingAlgorithm::INSERTION_SORT:
        insertionSort(arr, size);
        break;
    case SortingAlgorithm::QUICK_SORT:
        quickSort(arr, size);
        break;
    default:
        quickSort(arr, size);
        break;
    }
}

ostream &operator<<(ostream &out, const SortingAlgorithm algorithm)
{
    switch (algorithm)
    {
    case SortingAlgorithm::BUBBLE_SORT:
        return out << "Bubble Sort";
    case SortingAlgorithm::SELECTION_SORT:
        return out << "Selection Sort";
    case SortingAlgorithm::MERGE_SORT:
        return out << "Merge Sort";
    case SortingAlgorithm::INSERTION_SORT:
        return out << "Insertion Sort";
    case SortingAlgorithm::QUICK_SORT:
        return out << "Quick Sort";
    default:
        return out << "Default Sort";
    }
}