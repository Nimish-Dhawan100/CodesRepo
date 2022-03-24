#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;
using namespace chrono;
int subarraySum(vector<int> &arr, int k)
{
	int n = arr.size(); // take the size of the array

	int prefix[n]; // make a prefix array to store prefix sum

	prefix[0] = arr[0]; // for element at index at zero, it is same

	// making our prefix array
	for (int i = 1; i < n; i++)
	{
		prefix[i] = arr[i] + prefix[i - 1];
	}

	unordered_map<int, int> mp; // declare an unordered map

	int ans = 0; // to store the number of our subarrays having sum as 'k'

	for (int i = 0; i < n; i++) // traverse from the prefix array
	{
		if (prefix[i] == k) // if it already becomes equal to k, then increment ans
			ans++;

		// now, as we discussed find whether (prefix[i] - k) present in map or not
		if (mp.find(prefix[i] - k) != mp.end())
		{
			ans += mp[prefix[i] - k]; // if yes, then add it our answer
		}

		mp[prefix[i]]++; // put prefix sum into our map
	}
	return ans;
}
int subArrayExists(int arr[], int n)
{
	unordered_set<int> sumSet;
	int sum = 0, c = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
		if (sum == 0 || sumSet.find(sum) != sumSet.end())
			c++;
		sumSet.insert(sum);
	}
	return c;
}
int main()
{
	auto start1 = high_resolution_clock::now();
	int n;
	cout << "Enter The Length of Array" << endl;
	cin >> n;
	vector<int> arr(n);
	cout << "Enter The Elements of The Array" << endl;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int d = subarraySum(arr, n);
	cout << "The number of subarrays whose sum=0 are " << d << endl;
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
	cout << "Program completed in: " << duration.count() / 1000 << " milliseconds" << endl;
	return 0;
}
