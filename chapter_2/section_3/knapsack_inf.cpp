#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
using ll = long long;
static const int MAX_N = 101;

int n,W;
int w[MAX_N],v[MAX_N];
int dp[2][MAX_N];

//dp[i+1][j]:i番目までの品物から重さの総和がj以下となるように選んだ時の価値の最大値
int main(){
    cin >> n >> W;
    for(int i=0; i<n; i++){
        cin >> w[i] >> v[i];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<=W; j++){
            if(j<w[i]){
                dp[(i+1)&1][j]=dp[i&1][j];
            }
            else{
                dp[(i+1)&1][j]=max(dp[i&1][j], dp[(i+1)&1][j-w[i]]+v[i]);
                //右辺第二項がknapsack_memorize2と違う!
            }
        }
    }
    cout << dp[n&1][W];
    return 0;
}
//m mod 2^nは m&(2~n-1) により求まる!