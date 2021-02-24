#include <bits/stdc++.h>
#include <atcoder/all>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_bin_float.hpp>
using namespace boost::multiprecision;
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
#define rng1(a) a.begin() + 1, a.end()
#define rrng(a) a.rbegin(), a.rend()
#define isin(x, l, r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)), x.end())
#define snuke srand((unsigned)clock() + (unsigned)time(NULL));
#define show(x) cerr << #x << " = " << x << endl;
#define PQ(T) priority_queue<T, vector<T>, greater<T>>
#define bn(x) ((1 << x) - 1)
#define dup(x, y) (((x) + (y)-1) / (y))
#define newline puts("")
#define vv(T) vector<vector<T>>
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<bool> vb;
typedef vector<P> vp;
typedef vector<T> vt;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<vs> vvs;
typedef vector<vector<bool>> vvb;
typedef vvl graph;
typedef cpp_int cppi;
template <typename T>
istream &operator>>(istream &i, vector<T> &v)
{
    rep1(j, sz(v) - 1) i >> v[j];
    return i;
}
template <typename T1, typename T2>
inline istream &operator>>(istream &i, pair<T1, T2> &v)
{
    return i >> v.fi >> v.se;
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
const vl dx4{1, 0, -1, 0};
const vl dy4{0, -1, 0, 1};
const vl dx8{1, 1, 0, -1, -1, -1, 0, 1};
const vl dy8{0, -1, -1, -1, 0, 1, 1, 1};
constexpr ll MAX = 1e5 + 2;
constexpr ll LINF = 1e18 + 10;
constexpr ll mod = 1000000007;
//constexpr ll mod = 998244353;

int main()
{
    ll n, s;
    cin >> n >> s;
    vl a(n + 1);
    cin >> a;
    ll ans = LINF;
    ll r = 0;
    ll l = 0;
    ll sum = 0;
    //sum=a[l+1]+...+a[r]
    while (1)
    {
        while (1)
        {
            if (sum >= s)
                break;
            if (r == n)
                break;
            if (r + 1 <= n)
                r++;
            sum += a[r];
        }
        if (sum < s)
            break;
        chmin(ans, r - l);
        l++;
        sum -= a[l];
    }
    cout << ans << endl;
    return 0;
}