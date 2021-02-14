#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr ll MOD = 1000000007;
constexpr ll MAX = 2000;

ll S, ans;
ll fac[MAX], finv[MAX], inv[MAX];

void COMinit()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

ll COM(ll n, ll k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main()
{
    ans = 0;
    cin >> S; 
    if (S >= 3)
    {
        COMinit();
        for (ll i = 1; i <= S / 3; i++)
        {
            ans = (ans + COM(S - 2 * i - 1, i - 1)) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}