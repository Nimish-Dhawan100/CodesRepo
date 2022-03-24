#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
int main()
{
    auto start1 = high_resolution_clock::now();
    int size;
    cout << "Enter The Length of Array" << endl;
    cin >> size;
    int arr[size];
    cout << "Enter The Elements of The Array" << endl;
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    heapSort(arr, size);
    cout<<endl;
    cout << "Sorted array using Heap Sort is" << endl;
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    cout << "Program completed in: " << duration.count() / 1000 << " milliseconds" << endl;
    return 0;
}
