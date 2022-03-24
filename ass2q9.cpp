#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
int search(int arr[], int l, int h, int key)
{
	if (l > h)
		return -1;
	int mid = (l + h) / 2;
	if (arr[mid] == key)
		return mid;
	if (arr[l] <= arr[mid])
	{
		if (key >= arr[l] && key <= arr[mid])
			return search(arr, l, mid - 1, key);
		return search(arr, mid + 1, h, key);
	}
	if (key >= arr[mid] && key <= arr[h])
		return search(arr, mid + 1, h, key);
	return search(arr, l, mid - 1, key);
}
int main()
{
	auto start1 = high_resolution_clock::now();
	int n,key;
    cout<<"Enter The Length of Array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter The Elements of The Array"<<endl;
    for(int i=0;i<n;i++)
    cin>>arr[i];
	cout<<"Enter Target Element"<<endl;
	cin>>key;
    cout<<endl;
	int i = search(arr, 0, n - 1, key);
	if (i != -1)
		cout << "Element Found At Index: " << i << endl;
	else
		cout << "Key not found" << endl;
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
	cout << "Program completed in: " << duration.count() / 1000 << " milliseconds" << endl;
	return 0;
}
