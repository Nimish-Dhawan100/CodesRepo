#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using namespace chrono;
vector< pair<int, int> > findSubArrays(int arr[], int n)
{
	unordered_map<int, vector<int> > map;
	vector <pair<int, int> > out;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
		if (sum == 0)
			out.push_back(make_pair(0, i));
		if (map.find(sum) != map.end())
		{
			vector<int> vc = map[sum];
			for (auto it = vc.begin(); it != vc.end(); it++)
				out.push_back(make_pair(*it + 1, i));
		}
		map[sum].push_back(i);
	}
	return out;
}

int main()
{
    auto start1 = high_resolution_clock::now();
	int n;
    cout<<"Enter The Length of Array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter The Elements of The Array"<<endl;
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<endl;
	vector<pair<int, int> > out = findSubArrays(arr, n);
	if (out.size() == 0)
		cout << "No subarray exists"<<endl;
	else
		cout<<"The total subarrays having sum=0 are "<<out.size()<<endl;
    cout<<endl;
    auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
	cout << "Program completed in: " << duration.count() / 1000 << " milliseconds" << endl;
	
	return 0;
}
