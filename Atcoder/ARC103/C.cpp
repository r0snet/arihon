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
constexpr double eps = 1e-10;
constexpr ll LINF = 1001002003004005006ll;
constexpr int INF = 1001001001;
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

constexpr ll MAX = 100000;

int main()
{
    ll n, c = 0, d = 0, ans;
    cin >> n;
    ll dpe[MAX] = {}, dpo[MAX] = {};
    vector<ll> ve, vo;
    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        if (i % 2 == 0)
        {
            if (dpe[a] == 0)
            {
                ve.push_back(a);
            }
            dpe[a] += 1;
        }
        else
        {
            if (dpo[a] == 0)
            {
                vo.push_back(a);
            }
            dpo[a] += 1;
        }
    }
    vector<pair<ll, ll>> p1(ve.size()), p2(vo.size());
    for (int i = 0; i < ve.size(); i++)
    {
        p1[i].first = -1 * dpe[ve[i]];
        p1[i].second = ve[i];
    }
    sort(p1.begin(), p1.end());
    for (int i = 0; i < vo.size(); i++)
    {
        p2[i].first = -1 * dpo[vo[i]];
        p2[i].second = vo[i];
    }
    sort(p2.begin(), p2.end());
    if (p1[0].second == p2[0].second)
    {
        if (ve.size() == 1 && vo.size() == 1)
        {
            ans = n / 2;
        }
        else if (ve.size() == 1 && vo.size() == 2)
        {
            c = -1 * p1[0].first;
            d = -1 * p2[1].first;
            ans = n - c - d;
        }
        else if (ve.size() == 2 && vo.size() == 1)
        {
            c = -1 * p1[1].first;
            d = -1 * p2[0].first;
            ans = n - c - d;
        }
        else
        {
            if (-1 * p1[1].first > -1 * p2[1].first)
            {
                c = -1 * p1[1].first;
                d = -1 * p2[0].first;
            }
            else
            {
                c = -1 * p1[0].first;
                d = -1 * p2[1].first;
            }
            ans = n - c - d;
        }
    }
    else
    {
        c = -1 * p1[0].first;
        d = -1 * p2[0].first;
        ans = n - c - d;
    }
    cout << ans << endl;
    return 0;
}