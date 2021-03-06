#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
#include <set>
#include <climits>
#include <stack>
#include <unordered_map>
#include <queue>
#include <bitset>
#include <ctime>

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

bool isPalindrome(string str)
{
    string temp = str;
    reverse(temp.begin(), temp.end());
    return (temp == str);
}
int main()
{
    ll tc;
    cin >> tc;
    while (tc--)
    {
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        ll count = 0;
        ll i = 0, j = n - 1;
        bool flag = true;
        while (i < j)
        {
            if (count == k)
                break;
            if (s[i] != s[j])
            {
                flag = false;
                break;
            }
            else
            {
                count++;
                i++;
                j--;
            }
        }
        if (count == k && i <= j && flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}