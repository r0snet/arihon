//P.60
//重さ>>価値なので、価値に対する最小の重さを計算する.
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
static const int MAX_N = 100;
static const int MAX_V = 100;

int n, W;
int w[MAX_N], v[MAX_N];
int dp[MAX_N][MAX_N * MAX_V + 1];

//dp[i][j]:i番目までの品物から価値の総和がj以下となるように
//選んだ時の重さの和の最小値
int main()
{
    cin >> n >> W;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
    }
    fill(dp[0], dp[0] + MAX_N * MAX_V + 1, INF);
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= MAX_N * MAX_V; j++)
        {
            if (j < v[i])
            {
                dp[i + 1][j] = dp[i][j];
            }
            else
            {
                dp[i + 1][j] = min(dp[i][j], dp[i][j - v[i]] + w[i]);
                //v,wが前までと入れ替わっている
            }
        }
    }
    int res = 0;
    for (int i = 0; i <= MAX_N * MAX_V; i++)
        if (dp[n][i] <= W)
            res = i;
    cout << res << endl;
    return 0;
}
//計算量:O(n\sum(v_i))