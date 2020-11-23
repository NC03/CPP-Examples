/**
 * Sorting Example
 * 
 * @author NC03
 * @date November 19, 2020
 * @file
 * 
 */
#include "sorting.h"

using namespace std;
using namespace sorting;

void sorting::print(const int arr[], const int size);
void sorting::sort(int arr[], const int size, const SortingAlgorithm algorithm = SortingAlgorithm::DEFAULT);
ostream& sorting::operator<<(ostream &out, const SortingAlgorithm algorithm);

int main()
{
    cout << "sorting.cpp" << endl;

    srand(time(0));
    const int SIZE = 20;
    const int MAX = 300;
    const SortingAlgorithm algorithm = SortingAlgorithm::RADIX_SORT;

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
