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
constexpr ll MAX = 1000;

ll N, X, M;
ll vis[1 << 17], pre[1 << 17];
main()
{
    cin >> N >> X >> M;
    for (ll i = 0; i < M; i++)
        vis[i] = -1;
    ll ans = 0;
    ll tu = 0;
    while (N > 0)
    {
        if (vis[X] >= 0)
        {
            ll be = tu - vis[X];
            ans += (ans - pre[X]) * (N / be);
            N %= be;
        }
        if (N > 0)
        {
            vis[X] = tu++;
            pre[X] = ans;
            ans += X;
            N--;
            X = X * X % M;
        }
    }
    cout << ans << endl;
}