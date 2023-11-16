#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to partition the array and return the pivot index
int deterministicPartition(vector<int> &arr, int start, int end)
{
    int pivot = arr[end]; // Choose the last element as the pivot
    int i = start - 1;

    for (int j = start; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[end]);
    return i + 1;
}

// Function to perform deterministic quicksort
void deterministicQuickSort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int pivotIndex = deterministicPartition(arr, start, end);

        deterministicQuickSort(arr, start, pivotIndex - 1);
        deterministicQuickSort(arr, pivotIndex + 1, end);
    }
}

// Function to choose a random pivot and partition the array
int randomizedPartition(vector<int> &arr, int start, int end)
{
    // Choose a random pivot index between start and end
    int pivotIndex = start + rand() % (end - start + 1);

    // Swap the chosen pivot with the last element
    swap(arr[pivotIndex], arr[end]);

    // Call deterministicPartition with the new pivot
    return deterministicPartition(arr, start, end);
}

// Function to perform randomized quicksort
void randomizedQuickSort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int pivotIndex = randomizedPartition(arr, start, end);

        randomizedQuickSort(arr, start, pivotIndex - 1);
        randomizedQuickSort(arr, pivotIndex + 1, end);
    }
}

// Function to print the elements of the array
void printArray(const vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    // Seed for random number generation
    srand(time(0));

    // Input the size of the array
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    // Input the array elements
    vector<int> arr(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Copy the array for both variants
    vector<int> arrDet = arr;
    vector<int> arrRand = arr;

    // Perform deterministic quicksort
    cout << "\nDeterministic Quicksort:" << endl;
    deterministicQuickSort(arrDet, 0, n - 1);
    printArray(arrDet);

    // Perform randomized quicksort
    cout << "\nRandomized Quicksort:" << endl;
    randomizedQuickSort(arrRand, 0, n - 1);
    printArray(arrRand);

    return 0;
}
