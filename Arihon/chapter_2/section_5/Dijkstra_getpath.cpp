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
//入力データとして1行目に頂点数, 辺数, 始点 n m s が, i+1(iは1〜m)行目に無向辺がその間に張られる頂点対, 及びその辺のコスト a_i b_i c_i が与えられるとする.
//蟻本とは異なり, 頂点番号は1-index, つまり 1,...,n とする.

struct edge
{
    ll to;
    ll cost;
};

vector<vector<edge>> g;
vl dist;
vl pre;

void dijkstra(ll s)
{
    priority_queue<P, vp, greater<P>> q;
    dist[s] = 0;
    q.push({0, s});
    while (!q.empty())
    {
        P p = q.top();
        q.pop();
        ll v = p.second;
        if (dist[v] < p.first)
            continue;
        for (auto ne : g[v])
        {
            if (dist[ne.to] > dist[v] + ne.cost)
            {
                dist[ne.to] = dist[v] + ne.cost;
                pre[ne.to] = v;
                q.push({dist[ne.to], ne.to});
            }
        }
    }
}
//全経路を探索し, より低コストの道を発見したときそれを最短距離候補とすることを繰り返す.
//ptiority_queにより走査候補となるpairの取得や挿入が高速.
//低コストの道を発見した際に, 新頂点ne.toの直前の頂点としてvをprevに登録する.

vl get_path(ll g)
{
    vl path;
    while (g > 0)
    {
        path.eb(g);
        g = pre[g];
    }
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    ll n, m, s;
    cin >> n >> m >> s;
    g.resize(n + 1);
    dist.assign(n + 1, LINF);
    pre.resize(n + 1);
    rep(_, m)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        g[a].eb((edge){b, c});
        g[b].eb((edge){a, c});
    }
    dijkstra(s);
    rep1(i, n)
    {
        for (auto e : get_path(i))
            cout << e << " ";
        cout << endl;
    }
    //sからiへの最短路をi行目に表示.
    return 0;
}