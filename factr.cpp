#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
int fact(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return (n * fact(n - 1));
}
int main()
{
    auto start1 = high_resolution_clock::now();
    int n;
    cout<<"Enter The Number whose factorial is to be calculated"<<endl;
    cin>>n;
    cout<<"The Factorial of "<<n<<" is"<<" ";
    cout<<fact(n)<<endl;
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    cout << "Program completed in: " << duration.count() / 1000 << " milliseconds" << endl;
    return 0;
}