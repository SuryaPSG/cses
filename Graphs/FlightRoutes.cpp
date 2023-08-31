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

void solve(){
    ll n,m,k;
    cin>>n>>m>>k;
    vector<vector<pll>> adj(n+1);
    forl(i,0,m){
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({w,v});
    }
    vl vis(n+1);
    priority_queue<pll,vll,greater<pll>> Q;
    Q.push({0,1});
    while(!Q.empty()){
        auto [d,u]=Q.top();
        Q.pop();
        vis[u]++;
        if(u==n) cout<<d<<" ";
        if(vis[u]>k) continue;
        if(vis[n]==k) return;
        for(auto [w,v]:adj[u]){
            Q.push({d+w,v});
        }
    }
    cout<<endl;
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}