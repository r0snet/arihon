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
static const int MAX_K = 100001;

int n, K;
int a[MAX_N], m[MAX_N], dp[MAX_K];

int main()
{
    cin >> n >> K;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> m[i];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= K; j++)
        {
            //dp[j]はi番目まででjを作る際に余るa[i]の個数の最大値
            if (dp[j] >= 0)
            //i番目までで既にjが作れている場合
            {
                dp[j] = m[i];
                //dp[i+1][j]をdp[j]と書いている
            }
            else if (j >= a[i] && dp[j - a[i]] > 0)
            //i番目まででjが作れてはいないが(i+1)番目でできる場合
            {
                dp[j] = dp[j - a[i]] - 1;
                //dp[i+1][j]をdp[j]と書いている
            }
            else
            //jが作れない場合
            {
                dp[j] = -1;
                //dp[i+1][j]をdp[j]と書いている
            }
        }
    }
    if (dp[K] >= 0)
    {
        cout << "Yes." << endl;
    }
    else
    {
        cout << "No." << endl;
    }
    return 0;
}