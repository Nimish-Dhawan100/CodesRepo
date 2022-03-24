#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
void merge(int arr[], int p, int q, int r)
{
    int n = q - p + 1;
    int m = r - q;
    int L[n], M[m];
    for (int i = 0; i < n; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < m; j++)
        M[j] = arr[q + 1 + j];
    int i, j, k;
    i = 0;
    j = 0;
    k = p;
    while (i < n && j < m)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }
    while (i < n)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < m)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
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
    mergeSort(arr, 0, size - 1);
    cout<<endl;
    cout << "Sorted array by using Merge Sort is"<<endl;
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    cout << "Program completed in: " << duration.count() / 1000 << " milliseconds" << endl;
    return 0;
}

