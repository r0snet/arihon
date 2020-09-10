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
static const int MAX_N = 1001;

int n, m, M;
int a[MAX_N], dp[MAX_N][MAX_N];
// dp[i][j]はi番目までの品物からj個選ぶ組み合わせの数

int main()
{
    cin >> n >> m >> M;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (j > a[i])
            {
                dp[i + 1][j] = dp[i + 1][j - 1] + dp[i][j] - dp[i][j - a[i] - 1] % M;
            }
            else
            {
                dp[i + 1][j] = dp[i + 1][j - 1] + dp[i][j] % M;
            }
        }
    }
    cout << dp[n][m] << endl;
}