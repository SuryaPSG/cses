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

const ll md=1e9+7;

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<pll>> adj(n+1);
    forl(i,0,m){
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({w,v});
    }
    vl dist(n+1,0x3f3f3f3f3f3f3f3f);
    dist[1]=0;
    vl dp(n+1,0);
    dp[1]=1;
    priority_queue<vl,vvl,greater<vl>> Q;
    Q.push({0,1,1});
    vl vis(n+1);
    vl mn(n+1,0x3f3f3f3f3f3f3f3f),mx(n+1,LLONG_MIN);
    mn[1]=mx[1]=0;
    while(!Q.empty()){
        vl t=Q.top();
        ll u=t[1],c=t[2];
        Q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto [w,v]:adj[u]){
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                Q.push({dist[v],v,c+1});
                dp[v]=dp[u];
                mn[v]=mn[u]+1;
                mx[v]=mx[u]+1;
            }
            else if(dist[v]==dist[u]+w){
                dp[v]=(dp[u]+dp[v])%md;
                mn[v]=min(mn[v],mn[u]+1);
                mx[v]=max(mx[v],mx[u]+1);
            }
        }
    }
    cout<<dist[n]<<" "<<dp[n]<<" "<<mn[n]<<" "<<mx[n]<<endl;
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}