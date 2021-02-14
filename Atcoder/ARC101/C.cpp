#include <bits/stdc++.h>
typedef long long int ll;
#define fi first
#define se second
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (n); ++i)
#define rrep(i, n) for (ll i = (n)-1; i >= 0; --i)
#define srep(i, s, t) for (ll i = s; i < t; ++i)
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
constexpr ll MAX = 100001;

int main()
{
    string so, ans;
    int k;
    cin >> so;
    cin >> k;
    vector<pair<char, int>> s;
    for (int i = 0; i < so.size(); i++)
    {
        s.push_back(make_pair(so.at(i), i));
    }
    sort(s.begin(), s.end());
    char f = s[0].first;
    //cout << f << endl;
    if (so.size() - s[0].second >= k)
    {
        int i = 1;
        while (k >= 0)
        {
            vector<string> si;
            si.push_back(so.substr(s[0].second, i));
            for (int j = 1; s[j].first == s[0].first && j < so.size(); j++)
            {
                bool notin = 1;
                for (auto e : si)
                {
                    if (so.substr(s[j].second, i) == e)
                    {
                        notin = 0;
                    }
                }
                if (notin)
                {
                    si.push_back(so.substr(s[j].second, i));
                }
            }
            sort(si.begin(), si.end());
            for (auto e : si)
            {
                cout << i << " " << k << " " << e << " " << si.size() << endl;
            }
            if (si.size() >= k)
            {
                ans = si[k - 1];
                k -= si.size();
                break;
            }
            else
            {
                k -= si.size();
            }
            i += 1;
        }
    }
    else
    {
        k -= so.size() - s[0].second;
    }
    if (k > 0)
    {
        for (int i = 0; i < so.size(); i++)
        {
            if (s[i].first != f)
            {
                f = s[i].first;
                if (so.size() - s[i].second >= k)
                {
                    ans = so.substr(s[i].second, k);
                }
                else
                {
                    k -= so.size() - s[i].second;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}