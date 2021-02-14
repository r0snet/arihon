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
constexpr ll LINF = 1 << 29;
//constexpr ll mod = 1000000007;
constexpr ll mod = 998244353;

//連結とは限らないn頂点のグラフが与えられる. これが二部グラフか判定したい.
//入力データとして1行目に頂点数,辺数 n m が, i+1(iは1〜m)行目に無向辺がその間に張られる頂点対 a_i b_i が与えられるとする.
//蟻本とは異なり, 頂点番号は1-index, つまり 1,...,n とする.

graph g;
vl color;

bool coloring(ll v, ll c)
{
    color[v] = c;
    for (auto nv: g[v])
    {
        if (color[nv] == c)
            return false;
        if (color[nv] == -1 && !coloring(nv, 1 - c))
            return false;
    }
    return true;
}
//頂点vを色cで塗る. vの属する連結成分に対し, 隣り合う頂点の色は異なるように塗っていく.
//二色で塗りきれるときはTrue, 塗りきれないときはFalseを返す.

int main()
{
    ll n, m;
    cin >> n >> m;
    g.assign(n + 1, vl());
    color.assign(n + 1, -1);
    //頂点のリスト. これから色0,1で塗っていく. まだ見ていない頂点は-1にしておく.
    rep(_, m)
    {
        ll a, b;
        cin >> a >> b;
        g[a].eb(b), g[b].eb(a);
    }
    rep1(i, n) if (color[i] == -1) if (coloring(i, 0) == false)
    {
        cout << "No" << endl;
        return 0;
    }
    //未彩色の頂点を発見したらその頂点の属する連結成分を二色で塗る. 塗りきれなければその時点でNoを出力.
    cout << "Yes" << endl;
    return 0;
}