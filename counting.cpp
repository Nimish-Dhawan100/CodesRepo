#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
void display(int *array, int size)
{
	for (int i = 1; i <= size; i++)
		cout << array[i] << " ";
	cout << endl;
}
int getMax(int array[], int size)
{
	int max = array[1];
	for (int i = 2; i <= size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return max;
}
void countSort(int *array, int size)
{
	int output[size + 1];
	int max = getMax(array, size);
	int count[max + 1];
	for (int i = 0; i <= max; i++)
		count[i] = 0;
	for (int i = 1; i <= size; i++)
		count[array[i]]++;
	for (int i = 1; i <= max; i++)
		count[i] += count[i - 1];
	for (int i = size; i >= 1; i--)
	{
		output[count[array[i]]] = array[i];
		count[array[i]] -= 1;
	}
	for (int i = 1; i <= size; i++)
	{
		array[i] = output[i];
	}
}
int main()
{
	auto start1 = high_resolution_clock::now();
	int n;
	cout << "Enter The Length of Array" << endl;
	cin >> n;
	int array[n+1];
	cout << "Enter The Elements of The Array" << endl;
	for (int i = 1; i < n+1; i++)
		cin >> array[i];
	cout<<endl;
	countSort(array, n);
	cout << "Sorted array using Counting Sort is" << endl;
	display(array, n);
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
	cout << "Program completed in: " << duration.count() / 1000 << " milliseconds" << endl;
	return 0;
}