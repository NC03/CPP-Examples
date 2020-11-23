#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

namespace sorting
{
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
        COUNTING_SORT,
        RADIX_SORT,
        DEFAULT
    };

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
            std::cout << arr[i] << " ";
        }
        if (size > 0)
        {
            std::cout << arr[size - 1] << std::endl;
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
        int compIdx = size / 2;
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

    int max(int arr[], int size)
    {
        int max = arr[0];
        for (int i = 0; i < size; i++)
        {
            int element = arr[i];
            if (element > max)
            {
                max = element;
            }
        }
        return max;
    }

    /**
 * Sorts the given array using the counting sort algorithm
 * PRECONDITION: The elements must be nonnegative
 * 
 * @param arr The array to sort
 * @param size The number of elements in the array
 * 
 */
    void countingSort10(int arr[], int size)
    {
        int *copy = new int[size];
        int maxKey = max(arr, size);
        int freqLen = maxKey + 1;
        int *cumulativeFrequencies = new int[freqLen];
        for (int i = 0; i < freqLen; i++)
        {
            cumulativeFrequencies[i] = 0;
        }
        for (int i = 0; i < size; i++)
        {
            int element = arr[i];
            copy[i] = element;
            cumulativeFrequencies[element]++;
        }
        for (int i = 1; i < freqLen; i++)
        {
            cumulativeFrequencies[i] += cumulativeFrequencies[i - 1];
        }
        for (int i = size - 1; i >= 0; i--)
        {
            int element = copy[i];
            int idx = cumulativeFrequencies[element] - 1;
            arr[idx] = element;
            cumulativeFrequencies[element]--;
        }
        delete[] copy;
        delete[] cumulativeFrequencies;
    }

    /**
 * Sorts the given array using the radix sort algorithm
 * PRECONDITION: The elements must be nonnegative
 * 
 * @param arr The array to sort
 * @param size The number of elements in the array
 * 
 */
    void radixSort(int arr[], int size)
    {
        int *copy = new int[size];
        int *cumulativeFrequencies = new int[10];
        int numDigits = static_cast<int>(floor(log(max(arr, size)) / log(10))) + 1;
        for (int digit = 0; digit < numDigits; digit++)
        {
            for (int i = 0; i < 10; i++)
            {
                cumulativeFrequencies[i] = 0;
            }
            for (int i = 0; i < size; i++)
            {
                int element = arr[i];
                int key = (element / static_cast<int>(pow(10, digit))) % 10;
                copy[i] = element;
                cumulativeFrequencies[key]++;
            }
            for (int i = 1; i < 10; i++)
            {
                cumulativeFrequencies[i] += cumulativeFrequencies[i - 1];
            }
            for (int i = size - 1; i >= 0; i--)
            {
                int element = copy[i];
                int key = (element / static_cast<int>(pow(10, digit))) % 10;
                int idx = cumulativeFrequencies[key] - 1;
                arr[idx] = element;
                cumulativeFrequencies[key]--;
            }
        }
        delete[] copy;
        delete[] cumulativeFrequencies;
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
        case SortingAlgorithm::COUNTING_SORT:
            countingSort10(arr, size);
            break;
        case SortingAlgorithm::RADIX_SORT:
            radixSort(arr, size);
            break;
        default:
            quickSort(arr, size);
            break;
        }
    }

    std::ostream &operator<<(std::ostream &out, const SortingAlgorithm algorithm)
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
        case SortingAlgorithm::COUNTING_SORT:
            return out << "Counting Sort";
        case SortingAlgorithm::RADIX_SORT:
            return out << "Radix Sort";
        default:
            return out << "Default Sort";
        }
    }
} // namespace sorting

#endif //SORTING_H