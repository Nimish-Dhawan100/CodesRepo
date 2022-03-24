#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
int main()
{
    auto start1 = high_resolution_clock::now();
    int a = 1, b = 1, c, n;
    cout << "Enter The number of terms in Fibonacci sequence" << endl;
    cin >> n;
    cout << "The Fibonacci sequence of " << n << " numbers is" << endl;
    cout << a << " " << b << " ";
    for (int i = 2; i < n; ++i)
    {
        c = a + b;
        cout << c << " ";
        a = b;
        b = c;
    }
    cout << endl;
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    cout << "Program completed in: " << duration.count() / 1000 << " milliseconds" << endl;
    return 0;
}