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

vvl adj;
vvl up;
vl depth;
ll Log;

void dfs(ll u,ll p){
    if(u!=0) depth[u]=1+depth[p];
    up[u][0]=p;
    forl(i,1,Log) up[u][i]=up[up[u][i-1]][i-1];
    for(ll v:adj[u]) if(v!=p) dfs(v,u);
}

ll lca(ll u,ll v){
    if(depth[u]<depth[v]) swap(u,v);
    ll k=depth[u]-depth[v];
    for(ll j=Log;j>=0;j--){
        if((k>>j)&1) u=up[u][j];
    }
    if(u==v) return u;
    for(ll j=Log;j>=0;j--){
        if(up[u][j]!=up[v][j]){
            u=up[u][j];
            v=up[v][j];
        }
    }
    return up[u][0];
}

void solve(){
    ll n,q;
    cin>>n>>q;
    adj=vvl(n+1);
    depth=vl(n+1);

    Log=0;
    while((1<<Log)<=n) Log++;
    up=vvl(n+1,vl(Log+1));

    forl(i,2,n+1){
        ll p;
        cin>>p;
        adj[p].pb(i);
    }
    dfs(1,0);

    forl(i,0,q){
        ll u,v;
        cin>>u>>v;
        cout<<lca(u,v)<<endl;
    }
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}