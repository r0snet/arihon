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

long long a[MAX_N];

long long GCD(long long a, long long b)
{
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}

int main()
{
    long long n, a, b;
    cin >> n >> a;
    for (long long i = 1; i < n; i++)
    {
        cin >> b;
        a = GCD(a, b);
    }
    cout << a;
    return 0;
}