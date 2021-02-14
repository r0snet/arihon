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
static const int MAX_N = 1001;
int N, R;
int X[MAX_N];

int main()
{
    cin >> N >> R;
    for (int i = 0; i < N; i++)
    {
        cin >> X[i];
    }
    sort(X, X + N);
    int i = 0, ans = 0;
    while (i < N)
    {
        // まずカバーされていない領域のうちR以下ぎりぎりまで右に進む
        int s = X[i++];
        while (i < N && X[i] <= s + R)
            i++;          //sより右にR以下の距離にある点を1つ行き過ぎた点をiとする
        int p = X[i - 1]; //i-1番目の点を塗る
        while (i < N && X[i] <= p + R)
            i++;          //右に移動してカバーされている領域から脱出
        ans++;
    }
    cout << ans;
    return 0;
}