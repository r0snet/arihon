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

int main()
{
    long long T;
    cin >> T;
    for (long long i = 0; i < T; i++)
    {
        long long N;
        cin >> N;
        long long k;
        k = 0;
        for (long long j = 0; j < N; j++)
        {
            long long a;
            cin >> a;
            k += a % 2;
            k = k % 2;
        }
        N = N % 2;
        if (N == 1 || N + k == 0)
        {
            cout << "Second" << endl;
        }
        else
        {
            cout << "First" << endl;
        }
    }
    return 0;
}