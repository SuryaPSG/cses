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

void solve(){
    ll n,m,q;
    cin>>n>>m>>q;
    vvl dp(n+1,vl(n+1,LLONG_MAX));
    forl(i,0,m){
        ll u,v,w;
        cin>>u>>v>>w;
        dp[u][v]=min(dp[u][v],w);
        dp[v][u]=min(dp[v][u],w);;
    }
    forl(i,0,n+1) dp[i][i]=0;
    forl(k,1,n+1){
        forl(i,1,n+1){
            forl(j,1,n+1){
                if(dp[i][k]!=LLONG_MAX and dp[k][j]!=LLONG_MAX) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    forl(i,0,q){
        ll u,v;
        cin>>u>>v;
        if(dp[u][v]==LLONG_MAX) cout<<-1<<endl;
        else cout<<dp[u][v]<<endl;
    }
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}