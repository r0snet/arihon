#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using uint = unsigned int;
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rep1(i, n) for (int i = 1; i <= int(n); i++)
#define per(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define per1(i, n) for (int i = int(n); i > 0; i--)
#define all(c) c.begin(), c.end()
#define si(x) int(x.size())
#define pb emplace_back
#define fs first
#define sc second
template <class T>
using V = vector<T>;
template <class T>
using VV = vector<vector<T>>;
template <class T, class U>
void chmax(T &x, U y)
{
    if (x < y)
        x = y;
}
template <class T, class U>
void chmin(T &x, U y)
{
    if (y < x)
        x = y;
}
template <class T>
void mkuni(V<T> &v)
{
    sort(all(v));
    v.erase(unique(all(v)), v.end());
}
template <class S, class T>
ostream &operator<<(ostream &o, const pair<S, T> &p)
{
    return o << "(" << p.fs << "," << p.sc << ")";
}
template <class T>
ostream &operator<<(ostream &o, const vector<T> &vc)
{
    o << "{";
    for (const T &v : vc)
        o << v << ",";
    o << "}";
    return o;
}
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

bool solve()
{
    int N;
    cin >> N;
    V<int> a(N);
    rep(i, N) cin >> a[i];
    if (N & 1) return false;
    sort(all(a));
    rep(i, N / 2) if (a[i + i] != a[i + i + 1]) return true;
    return false;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false); //DON'T USE scanf/printf/puts !!
    cout << fixed << setprecision(20);

    int T;
    cin >> T;
    while (T--)
        cout << (solve() ? "First" : "Second") << '\n';
}