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

//一度通った道を再び通ってもよいことに注意.

struct edge
{
    ll to;
    ll cost;
};

vector<vector<edge>> g;
vl dist1, dist2;

void dijkstra(ll s)
{
    priority_queue<P, vp, greater<P>> q;
    dist1[s] = 0;
    q.push({0, s});
    while (!q.empty())
    {
        P pp = q.top();
        q.pop();
        ll pv = pp.second;
        ll pc = pp.first;
        if (dist2[pv] < pc)
            continue;
        for (auto ne : g[pv])
        {
            ll nv = ne.to;
            ll nc = ne.cost;
            ll d2 = pc + nc;
            if (dist1[nv] > d2)
            {
                swap(dist1[nv], d2);
                q.push({dist1[nv], nv});
            }
            else if (dist1[nv] < d2 && d2 < dist2[nv])
            {
                dist2[nv] = d2;
                q.push({dist2[nv], nv});
            }
        }
    }
}

int main()
{
    ll n, m;
    cin >> n >> m;
    g.resize(n + 1);
    dist1.assign(n + 1, LINF);
    dist2.assign(n + 1, LINF);
    rep(_, m)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        g[a].eb((edge){b, c});
        g[b].eb((edge){a, c});
    }
    dijkstra(1);
    //rep1(i, n) cout << i << " " << dist1[i] << " " << dist2[i] << endl;
    cout << dist2[n] << endl;
    return 0;
}