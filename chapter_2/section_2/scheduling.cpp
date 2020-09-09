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
static const int MAX_N = 100000;
static const int MAX_M = 100000;

int N;
pair<long, long> P[MAX_N];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> P[i].second;
    }
    for (int i = 0; i < N; i++)
    {
        cin >> P[i].first;
    }
    sort(P, P + N);
    int ans = 0, t = 0;
    // tは最後に選んだ仕事の終了時刻
    for (int i = 0; i < N; i++)
    {
        if (t < P[i].second){
            t = P[i].first;
            ans++;
        }
    }
    cout << ans;
    return 0;
}