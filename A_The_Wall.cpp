#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

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
    // ll x, y, a, b, count = 0;
    // cin >> x >> y >> a >> b;
    // // 1-a 1- a+B
    // ll tillA = b / x - a / x;
    // ll tillB = b / y - a / y;

    // ll tillAB = (a + b) / y;

    // cout << count << endl;

    ll n, x, m;
    cin >> n;
    cin >> m;
    vector<pair<ll, ll>> pp(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> x;
        pp[i].first = x % m;
        pp[i].second = i + 1;
    }
    sort(pp.begin(), pp.end());
    ll q;
    cin >> q;
    while (q--)
    {
        ll x;
        cin >> x;
        ll low = 0, high = n - 1, ans = 0;
        while (low <= high)
        {
            ll mid = (low + high) / 2;
            ll check = (pp[mid].first + x % m) % m;
            if (check <= pp[mid].first)
            {
                high = mid - 1;
                ans = pp[mid].second;
            }
            else
            {
                low = mid + 1;
            }
        }
        cout << ans << endl;
    }
}