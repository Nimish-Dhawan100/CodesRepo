#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
int main()
{
    auto start1 = high_resolution_clock::now();
    int n;
    cout<<"Enter The Number whose factorial is to be calculated"<<endl;
    cin>>n;
    cout<<"The Factorial of "<<n<<" is"<<" ";
    long long ans=1;
    for(int i=2;i<=n;i++)
    ans*=i;
    cout<<ans<<endl;
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    cout << "Program completed in: " << duration.count() / 1000 << " milliseconds" << endl;
    return 0;
}