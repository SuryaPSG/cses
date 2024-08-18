#include<bits/stdc++.h>
using namespace std;
#define DONTSYNC ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL) //dont use stdio with iostream functions //input and output are out of order now!
#define TEST long long T; cin>>T; while(T--)
#define endl "\n"
#define fori(a,start,end) for(int a=start;a<end;a++)
#define forl(a,start,end) for(long long a=start;a<end;a++)
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long     ll;
typedef long double   ld;
typedef pair<int,int> pii;
typedef pair<ll,ll>   pll;
typedef vector<int>   vi;
typedef vector<ll>    vl;
typedef vector<pii>   vii;
typedef vector<pll>   vll;
typedef vector<vi>    vvi;
typedef vector<vl>    vvl;
typedef unordered_map<ll,ll> umll;
typedef map<ll,ll> mll;
typedef unordered_set<ll> usll;
typedef set<ll> sll;
const double PI = acos(-1);
const ll INF=0x3f3f3f3f3f3f3f3f;

vl path(48);
ll dir[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
ll dp[9][9];

int solve(int idx,int x,int y){
    if(dp[x-1][y] && dp[x+1][y] && !dp[x][y-1] && !dp[x][y+1]) return 0;
    if(dp[x][y-1] && dp[x][y+1] && !dp[x-1][y] && !dp[x+1][y]) return 0;
    if(x==7 and y==1){
        if(idx==48) return 1;
        return 0;
    }
    if(idx==48) return 0;
    dp[x][y]=1;
    int res=0;
    if(path[idx]<4){
        int nx=x+dir[path[idx]][0];
        int ny=y+dir[path[idx]][1];
        if(!dp[nx][ny]) res+=solve(idx+1,nx,ny);
    }
    else{
        for(int i=0;i<4;i++){
            int nx=x+dir[i][0];
            int ny=y+dir[i][1];
            if(!dp[nx][ny]) res+=solve(idx+1,nx,ny);
        }
    }
    dp[x][y]=0;
    return res;
}


void solve(){
    string str;
    cin>>str;
    for(int i=0;i<48;i++){
        if(str[i]=='D') path[i]=0;
        else if(str[i]=='U') path[i]=1;
        else if(str[i]=='L') path[i]=2;
        else if(str[i]=='R') path[i]=3;
        else path[i]=4;
    }
    memset(dp,0,sizeof(dp));
    forl(i,0,9){
        dp[i][0]=1;
        dp[i][8]=1;
        dp[0][i]=1;
        dp[8][i]=1;
    }
    cout<<solve(0,1,1)<<endl;
}

int main()
{
    DONTSYNC;
    //TEST
    solve();
    return 0;
}