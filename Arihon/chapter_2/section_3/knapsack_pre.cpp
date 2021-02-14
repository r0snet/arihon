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
using namespace std;
#define MOD 1000000007
#define INF (1 << 29)
#define LINF (1LL << 60)
#define EPS (1e-10)
static const int MAX_N = 101;

int n, W;
int w[MAX_N], v[MAX_N];
//i番目以降の品物から重さの総和がj以下となるよう選ぶ
int rec(int i, int j)
{
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
    return res;
}

int main()
{
    cin >> n >> W;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
    }
    cout << rec(0, W);
    return 0;
}