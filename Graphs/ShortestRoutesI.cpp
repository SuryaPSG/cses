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
    ll n,m;
    cin>>n>>m;
    vector<vector<pll>> adj(n+1);
    forl(i,0,m){
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({w,v});
    }
    vl dist(n+1,LONG_MAX);
    dist[1]=0;
    vl vis(n+1);
    priority_queue<pll,vll,greater<pll>> Q;
    Q.push({0,1});
    while(!Q.empty()){
        auto [d,u]=Q.top();
        Q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto [w,v]:adj[u]){
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                Q.push({dist[v],v});
            }
        }
    }
    forl(i,1,n+1) cout<<dist[i]<<" ";
    cout<<endl;
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}