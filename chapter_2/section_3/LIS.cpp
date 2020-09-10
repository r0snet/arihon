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

int n;
int a[MAX_N], dp[MAX_N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    fill(dp, dp + n, INF);
    for (int i = 0; i < n; i++)
    {
        *lower_bound(dp, dp + n, a[i]) = a[i];
    }
    cout << lower_bound(dp, dp + n, INF) - dp << endl;
    return 0;
}