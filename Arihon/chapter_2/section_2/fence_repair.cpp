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
static const int MAX_N = 50001;

int N, L[MAX_N];
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> L[i];
    }
    ll ans = 0;
    while (N > 1)
    {
        int mii1 = 0, mii2 = 1;
        if (L[mii1] > L[mii2])
            swap(mii1, mii2);

        for (int i = 2; i < N; i++)
        {
            if (L[i] < L[mii1])
            {
                mii2 = mii1;
                mii1 = i;
            }
            else if (L[i] < L[mii2])
            {
                mii2 = i;
            }
        }
        int t = L[mii1] + L[mii2];
        ans += t;
        if (mii1 == N - 1)
            swap(mii1, mii2);
        L[mii1] = t;        //一番小さかったとこに（1,2番目に小さいものの和）を代入
        L[mii2] = L[N - 1]; //二番目に小さかったとこに元のN番目の値を代入
        N--;
    }
    cout << ans;
}