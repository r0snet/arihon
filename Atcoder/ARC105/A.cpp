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
#define MAX_N (20)

int a[MAX_N];
int n, k;
bool dfs(int i, int sum)
{
    if (i == n)
        return sum == k / 2;
    if (dfs(i + 1, sum))
        return true;
    if (dfs(i + 1, sum + a[i]))
        return true;
    return false;
}
int main()
{
    n = 4;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    k = 0;
    for (int i = 0; i < n; i++)
    {
        k += a[i];
    }
    if (k % 2 == 0 && (dfs(0, 0)))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}