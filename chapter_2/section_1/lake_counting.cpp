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

static const int MAX_N = 100;
static const int MAX_M = 100;
int n, m;
char field[MAX_N][MAX_M];

void dfs(int x, int y)
{
    field[x][y] = '.'; //現在位置を.に
    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            int nx = x + dx;
            int ny = y + dy;
            if (0 <= nx && nx < n && 0 <= ny && ny < m && field[nx][ny] == 'W')
                dfs(nx, ny);
            // Wを八近傍に発見したらそこに移動して再帰
        }
    }
    return;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> field[i][j];
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (field[i][j] == 'W')
            {
                dfs(i, j);
                res++; // 再帰まで含めて一回としたdfsの呼び出し回数が水たまりの個数
            }
        }
    }
    cout << res;
    return 0;
}