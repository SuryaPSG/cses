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
const ll mx=501;
ll cap[mx][mx];
vl par(mx),adj[mx];
ll n,m;
ll bfs(ll s,ll t){
    fill(all(par),-1);
    par[s]=-2;
    queue<pll> q;
    q.push({s,INF});
    while(!q.empty()){
        auto [u,f]=q.front();
        q.pop();
        for(ll v:adj[u]){
            if(par[v]==-1 and cap[u][v]){
                par[v]=u;
                ll nf=min(f,cap[u][v]);
                if(v==t) return nf;
                q.push({v,nf});
            }
        }
    }
    return 0;
}
void solve(){
    cin>>n>>m;
    memset(cap,0,sizeof(cap));
    forl(i,0,m){
        ll a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
        cap[a][b]+=c;
    }
    ll res=0;
    while(ll f=bfs(0,n-1)){
        res+=f;
        int c=n-1;
        while(c!=0){
            cap[par[c]][c]-=f;
            cap[c][par[c]]+=f;
            c=par[c];
        }
    }
    cout<<res<<endl;
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}