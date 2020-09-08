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

int n, m;
char maze[MAX_N + 1][MAX_M + 1];
int sx, sy;
int gx, gy;
int d[MAX_N + 1][MAX_M + 1];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int bfs()
{
    queue<P> que;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            d[i][j] = INF;
        }
    }
    que.push(P(sx, sy));
    d[sx][sy] = 0;

    while (que.size())
    {
        P p = que.front();
        que.pop();
        if (p.first == gx && p.second == gy)
            break;
        for (int i = 0; i < 4; i++)
        {
            int nx = p.first + dx[i], ny = p.second + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && maze[nx][ny] != '#' && d[nx][ny] == INF)
            {
                que.push(P(nx, ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    return d[gx][gy];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> maze[i][j];
            if (maze[i][j] == 'S')
            {
                sx = i;
                sy = j;
            }
            if (maze[i][j] == 'G')
            {
                gx = i;
                gy = j;
            }
        }
    }
    int res = bfs();
    cout << res;
    return 0;
}