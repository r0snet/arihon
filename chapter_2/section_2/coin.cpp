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
typedef pair<int, int> P;
static const int MAX_N = 100;
static const int MAX_M = 100;

int A;
int c[6];
int v[6] = {1, 5, 10, 50, 100, 500};

int main()
{
    for (int i = 0; i < 6; i++)
    {
        cin >> c[i];
    }
    cin >> A;
    int ans = 0;
    for (int i = 5; i >= 0; i--)
    {
        int t = min(A / v[i], c[i]);
        A -= t * v[i];
        ans += t;
    }
    cout << ans;
    return 0;
}