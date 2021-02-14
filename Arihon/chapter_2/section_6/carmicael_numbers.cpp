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

bool is_prime(ll n)
{
    if (n == 1)
        return false;
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    ll n;
    cin >> n;
    if (is_prime(n))
    {
        cout << "No" << endl;
        return 0;
    }
    srep(x, 2, n)
    {
        if (pow_mod(x, n, n) != x)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}