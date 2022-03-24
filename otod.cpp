#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define mod1 998244353
#define ins insert
#define pb push_back
#define pob pop_back
#define mp make_pair
#define vec vector
#define ff first
#define ss second
#define fix(x) fixed << setprecision(x)
#define len(x) ((ll)(x).size())
#define rev reverse
#define endl "\n"
#define fo(i, a, b) for (int i = a; i < b; i++)
#define fol(i, a, b) for (ll i = a; i < b; i++)
#define fore(i, a, b) for (int i = a; i >= b; i--)
#define forl(i, a, b) for (ll i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()
#define alld(x) (x).rbegin(), (x).rend()
#define uniq(a) a.resize(unique(a.begin(), a.end()) - a.begin());
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;
#ifndef ONLINE_JUDGE
#define deb(x)         \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define deb(x)
#endif
void _print(ll t)
{
    cerr << t;
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(ld t) { cerr << t; }
void _print(double t) { cerr << t; }
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
bool _isprime(ll x)
{
    if ((x == 2) || (x == 3))
        return true;
    if ((x < 2) || (x % 2 == 0) || (x % 3 == 0))
        return false;
    ll t = 1;
    for (ll i = 5; i * i <= x; i += 2 * (1 + t))
    {
        if (x % i == 0)
            return false;
        t = 1 - t;
    }
    return true;
}
bool cmpa(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}
bool cmpd(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}
void solve()
{
    string s;
    cin >> s;
    ll sum = 0;
    ll j = 0;
    fore(i, len(s) - 1, 0)
    {
        sum += (s[i] - '0') * pow(8, j);
        j++;
    }
    cout << sum << endl;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}