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
int dp[MAX_N][MAX_N]; //dp[i][j]はjのi以下分割の個数

int main()
{
    cin >> n;
    cin >> m;
    cin >> M;
    dp[0][0] = 1;//0C0=1
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (j >= i)
                dp[i][j] = dp[i][j - i] + dp[i - 1][j] % M;
            else
                dp[i][j] = dp[i - 1][j] % M;
        }
    }
    cout << dp[m][n] << endl;
}