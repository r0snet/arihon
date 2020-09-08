#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
#define MOD 1000000007
#define INF (1 << 29)
#define LINF (1LL << 60)
#define EPS (1e-10)
static const int MAX_N = 101;

int n, W;
int w[MAX_N], v[MAX_N];
int dp[MAX_N][MAX_N];

int rec(int i, int j)
{
    if (dp[i][j] >= 0)
    {
        return dp[i][j];
    }
    int res = 0;
    if (i == n)
    {
        res = 0;
    }
    else if (j < w[i])
    {
        res = rec(i + 1, j);
    }
    else
    {
        res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
    }
    return dp[i][j] = res;
}

int main()
{
    cin >> n >> W;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << rec(0, W);
    return 0;
}