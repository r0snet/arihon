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
#define rng(a) a.begin() + 1, a.end()
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
constexpr ll LINF = 1e18;
//constexpr ll mod = 1000000007;
constexpr ll mod = 998244353;

vl a;
vvl memo;
//p^2は大きいのでmemoのサイズはq^2くらいにしないとMLEしそう.

ll dp(ll i, ll j)
{
    if (memo[i][j] != -1)
        return memo[i][j];
    if (j - i == 1)
    {
        memo[i][j] = 0;
        return memo[i][j];
    }
    ll res = LINF;
    srep1(k, i + 1, j - 1) chmin(res, dp(i, k) + dp(k, j));
    res += a[j] - a[i] - 2;//k番目の囚人の開放にかかるコスト.kに依存しない.
    memo[i][j] = res;
    return memo[i][j];
}
//区間DPのメモ化再帰. 
//dp(i,j)={区間(i,j)において部屋i,jは空かつ他の部屋は全て埋まっている状況で,(i,j)内の囚人を全て開放する最小コスト}

int main()
{
    ll p, q;
    cin >> p >> q;
    a.resize(q + 1);
    cin >> a;
    a.eb(p + 1);
    memo.assign(q + 2, vl(q + 2, -1));
    cout << dp(0, q + 1) << endl;
    return 0;
}