#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
typedef long long int ll;
typedef long double ld;
#define fi first
#define se second
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep0(i, n) for (ll i = 0; i <= (n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (n); ++i)
#define rrep1(i, n) for (ll i = (n); i > 0; --i)
#define rrep0(i, n) for (ll i = (n); i >= 0; --i)
#define srep(i, s, t) for (ll i = s; i < t; ++i)
#define srep1(i, s, t) for (ll i = s; i <= t; ++i)
#define rsrep1(i, s, t) for (ll i = s; i >= t; --i)
#define rng(a) a.begin(), a.end()
#define rrng(a) a.rbegin(), a.rend()
#define isin(x, l, r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)), x.end())
#define snuke srand((unsigned)clock() + (unsigned)time(NULL));
#define show(x) cerr << #x << " = " << x << endl;
#define PQ(T) priority_queue<T, v(T), greater<T>>
#define bn(x) ((1 << x) - 1)
#define dup(x, y) (((x) + (y)-1) / (y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<bool> vb;
typedef vector<P> vp;
typedef vector<T> vt;
typedef vector<string> vs;
typedef vector<vl> vvl;
typedef vector<vs> vvs;
typedef vector<vector<bool>> vvb;
typedef vvl graph;
template <typename T>
istream &operator>>(istream &i, v(T) & v)
{
    rep1(j, sz(v) - 1) i >> v[j];
    return i;
}
template <typename T>
void chmin(T &a, const T &b) { a = min(a, b); }
template <typename T>
void chmax(T &a, const T &b) { a = max(a, b); }
#define dame        \
    {               \
        puts("-1"); \
        return 0;   \
    }
#define yn           \
    {                \
        puts("Yes"); \
    }                \
    else { puts("No"); }
constexpr ll MAX = 1e9 + 2;
constexpr ll LINF = powl(10, 18);
//constexpr ll mod = 1000000007;
constexpr ll mod = 998244353;

//n頂点の連結グラフが与えられる. これに対する単一始点最短路問題を解きたい.
//入力データとして1行目に頂点数, 辺数 n m が, i+1(iは1〜m)行目に無向辺がその間に張られる頂点対, 及びその辺のコスト a_i b_i c_i が与えられるとする.
//蟻本とは異なり, 頂点番号は1-index, つまり 1,...,n とする.

ll n, m;
graph g;
vvl dist;

void warshall_froid()
{
    rep1(k, n)
    {
        rep1(i, n) rep1(j, n) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }
}
//DP.
//i,jへの経路として1,...,kを通る場合の最短路長をdist[i][j][k]とおくと
//dist[i][j][k]=min(dist[i][j][k-1],dist[i][k][k-1]+dist[k][j][k-1]). これを二次元配列で表現し直している.
//kステップ目における全ての(i,j)についてdist[i][j]を更新していくのでループはこの順.

int main()
{
    cin >> n >> m;
    g.resize(n + 1);
    dist.assign(n + 1, vl(n + 1, LINF));
    rep(_, m)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = c;
        dist[b][a] = c;
    }
    rep1(i, n) dist[i][i] = 0;
    warshall_froid();
    rep1(i, n) rep1(j, n) cout << i << " " << j << " " << dist[i][j] << endl;
    return 0;
}