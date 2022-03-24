#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
int fib(int n)
{
    if (n == 1 || n == 0)
        return n;
    else
        return (fib(n - 1) + fib(n - 2));
}
int main()
{
    auto start1 = high_resolution_clock::now();
    long long n;
    cout << "Enter The number of terms in Fibonacci sequence" << endl;
    cin >> n;
    cout << "The Fibonacci sequence of " << n << " terms is" << endl;
    for (int i = 1; i <= n; i++)
        cout << fib(i) << " ";
    cout << endl;
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    cout << "Program completed in: " << duration.count() / 1000 << " milliseconds" << endl;
}