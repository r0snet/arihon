#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
using ll = long long;
static const int MAX_N = 2001;

int N;
char S[MAX_N];

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> S[i];
    }
    int a=0, b=N-1;
    while(a<=b){
        bool left=false;
        for(int i=0; a+i<=b; i++){
            if(S[a+i]<S[b-i]){
                left=true;
                break;
            }
            else if(S[a+i]>S[b-i]){
                left=false;
                break;
            }
        }
        if(left) putchar(S[a++]);
        else putchar(S[b--]);
    }
    putchar('\n');
    return 0;
}