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
vl adj[mx],radj[mx],vis(mx),order,who(mx);
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
}
void solve(){
    ll n,m;
    cin>>n>>m;
    forl(i,0,n){
        char c1,c2;
        ll a,b;
        cin>>c1>>a>>c2>>b;
        a--;
        b--;
        a*=2;
        b*=2;
        if(c1=='-') a^=1;
        if(c2=='-') b^=1;
        adj[a^1].pb(b);
        adj[b^1].pb(a);
    }
    forl(i,0,2*m){
        for(ll v:adj[i]) radj[v].pb(i); 
    }
    forl(i,0,2*m) if(!vis[i]) dfs1(i);
    for(ll i=2*m-1;~i;i--){
        if(vis[order[i]]){
            dfs2(order[i],i);
        }
    }
    forl(i,0,m){
        if(who[2*i]==who[2*i+1]){
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
    }
    forl(i,0,m){
        cout<<( (who[2*i]<who[2*i+1]) ? '+':'-')<<" ";
    }
    cout<<endl;
}

int main()
{
    DONTSYNC;
    //TEST
    solve();
    return 0;
}