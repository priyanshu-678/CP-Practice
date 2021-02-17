#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <climits>

using namespace std;

#define mod 998244353
#define lli long long int
#define ll long long
#define li long int
#define FastIO               \
    ios::sync_with_stdio(0); \
    cin.tie(0)

class PNC
{
public:
    vector<unsigned lli> f;
    lli m;
    PNC(lli n, lli m = mod)
    {
        f.resize(n + 1);
        this->m = m;
        f[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            f[i] = (i * f[i - 1]) % m;
        }
    }
    lli power(lli b, lli p, lli m = mod)
    {
        lli res = 1;
        while (p > 0)
        {
            if (p & 1)
                res = ((res % m) * (b % m)) % m;
            b = ((b % m) * (b % m)) % m;
            p = p >> 1;
        }
        return res;
    }
    lli modInverse(lli n, lli m = mod) { return power(n, m - 2, m); }
    lli factorial(lli n) { return f[n]; }
    lli nCr(lli n, lli r)
    {
        if (r == 0)
            return 1;
        return (f[n] * modInverse(f[r], m) % m * modInverse(f[n - r], m) % m) % m;
    }
    lli nPr(lli n, lli r)
    {
        if (r == 0)
            return 1;
        return (f[n] * modInverse(f[n - r], m) % m) % m;
    }
};

int main()
{
    FastIO;
    ll tc;
    cin >> tc;
    while (tc--)
    {
        ll n, x;
        cin >> n;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
            cin >> v[i];
        ll i = 0, j = n - 1;
        if (v[i] != 1)
        {
            cout << "no" << endl;
            continue;
        }
        bool flag = true;
        while (i < j)
        {
            if (v[i] != v[j])
            {
                flag = false;
                break;
            }
            else if ((v[i] != v[i + 1]) && ((v[i] + 1) != v[i + 1]))
            {
                flag = false;
                break;
            }
            i++;
            j--;
        }
        if (v[i] != 7)
            flag = false;
        if (flag)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}