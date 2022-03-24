#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return (i + 1);
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}
int main()
{
    auto start1 = high_resolution_clock::now();
    int size;
    cout<<"Enter The Length of Array"<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter The Elements of The Array"<<endl;
    for(int i=0;i<size;i++)
    cin>>arr[i];
    cout<<endl;
    quickSort(arr, 0, size - 1);
    cout << "Sorted array using Quick Sort is"<<endl;
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    cout << "Program completed in: " << duration.count() / 1000 << " milliseconds" << endl;
    return 0;
}