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
        return sum == k;
    if (dfs(i + 1, sum))
        return true;
    if (dfs(i + 1, sum + a[i]))
        return true;
    return false;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> k;
    if (dfs(0, 0))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}