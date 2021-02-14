#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
#define rrep(i, n) for (int i = (n)-1; i >= 0; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
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
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;
int getInt()
{
    int x;
    scanf("%d", &x);
    return x;
}
template <typename T>
istream &operator>>(istream &i, v(T) & v)
{
    rep(j, sz(v)) i >> v[j];
    return i;
}
template <typename T>
string join(const v(T) & v)
{
    stringstream s;
    rep(i, sz(v)) s << ' ' << v[i];
    return s.str().substr(1);
}
template <typename T>
ostream &operator<<(ostream &o, const v(T) & v)
{
    if (sz(v))
        o << join(v);
    return o;
}
template <typename T1, typename T2>
istream &operator>>(istream &i, pair<T1, T2> &v) { return i >> v.fi >> v.se; }
template <typename T1, typename T2>
ostream &operator<<(ostream &o, const pair<T1, T2> &v) { return o << v.fi << "," << v.se; }
template <typename T>
bool mins(T &x, const T &y)
{
    if (x > y)
    {
        x = y;
        return true;
    }
    else
        return false;
}
template <typename T>
bool maxs(T &x, const T &y)
{
    if (x < y)
    {
        x = y;
        return true;
    }
    else
        return false;
}
template <typename T>
ll suma(const v(T) & a)
{
    ll res(0);
    for (auto &&x : a)
        res += x;
    return res;
}
constexpr double eps = 1e-10;
constexpr ll LINF = 1001002003004005006ll;
constexpr int INF = 1001001001;
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
constexpr int MAX = 1000001;

int par[MAX], rank{MAX}; //親,帰の深さ
//n要素で初期化,各要素が単一の木
void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = i;
        ::rank[i] = 0;
    }
}
//木の根を求める
int find(int x)
{
    if (par[x] == x)
    {
        return x;
    }
    else
    {
        return par[x] = find(par[x]);
    }
}
//x,yの属する集合を併合
void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    if (::rank[x] < ::rank[y])
    {
        par[x] = y;
    }
    else
    {
        par[y] = x;
    }
    if (::rank[x] == ::rank{y})
        ::rank[x]++;
    //::rank[x]<::rank[y]のときはyの根の直下にxを繋ぐのでランクは::rank[y]になる
}
//x,yが同じ集合に属するかどうか
bool same(int x, int y)
{
    return find(x) == find(y);
}