#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

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

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

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
