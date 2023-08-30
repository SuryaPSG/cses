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



void dfs(ll u,vvl &adj,vl &vis){
    vis[u]=1;
    for(ll v:adj[u]) if(!vis[v]) dfs(v,adj,vis);
}

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,pll>> Edge;
    vvl adj1(n+1),adj2(n+1);
    vl vis1(n+1),vis2(n+1);
    forl(i,0,m){
        ll u,v,w;
        cin>>u>>v>>w;
        Edge.pb({-w,{u,v}});
        adj1[u].pb(v);
        adj2[v].pb(u);
    }
    dfs(1,adj1,vis1);
    dfs(n,adj2,vis2);
    vl dist(n+1,LLONG_MAX);
    dist[1]=0;
    forl(i,0,n-1){
        forl(j,0,m){
            ll w=Edge[j].fi;
            ll u=Edge[j].se.fi;
            ll v=Edge[j].se.se;
            if(dist[u]!=LLONG_MAX and dist[u]+w<dist[v])dist[v]=dist[u]+w;
        }
    }
    forl(j,0,m){
        ll w=Edge[j].fi;
        ll u=Edge[j].se.fi;
        ll v=Edge[j].se.se;
        if(dist[u]!=LLONG_MAX and dist[u]+w<dist[v]){
            if(vis1[v] and vis2[v]){
                cout<<"-1"<<endl;
                return;
            }
        }
    }
    cout<<-dist[n]<<endl;
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}