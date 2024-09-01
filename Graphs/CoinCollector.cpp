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
const ll mx=2e5+10;
vl adj[mx],adj2[mx],radj[mx],vis(mx),order,who(mx),x(mx),y(mx),dp(mx);
void dfs1(int u){
    vis[u]=1;
    for(ll v:adj[u]){
        if(!vis[v]) dfs1(v);
    }
    order.pb(u);
}
void dfs2(int u,int p){
    vis[u]=0;
    who[u]=p;
    for(ll v:radj[u]){
        if(vis[v]) dfs2(v,p);
    }
    y[who[u]]+=x[u];
}
void dfs3(int i){
    vis[i]=1;
    for(ll v:adj2[i]){
        if(!vis[v]){
            dfs3(v);
        }
        dp[i]=max(dp[i],dp[v]);
    }
    dp[i]+=y[i];
}
void solve(){
    ll n,m;
    cin>>n>>m;
    forl(i,0,n) cin>>x[i];
    forl(i,0,m){
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].pb(b);
        radj[b].pb(a);
    }
    forl(i,0,n) if(!vis[i]) dfs1(i);
    for(ll i=n-1;i>=0;i--){
        if(vis[order[i]]){
            dfs2(order[i],order[i]);
        }
    }
    forl(i,0,n){
        for(ll j:adj[i]) if(who[i]!=who[j]) adj2[who[i]].pb(who[j]);
    }
    ll ans=0;
    forl(i,0,n){
        if(who[i]==i and !vis[i]) dfs3(i),ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
}

int main()
{
    DONTSYNC;
    //TEST
    solve();
    return 0;
}