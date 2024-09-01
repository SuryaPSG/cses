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
ll n,m,k;
const ll mx=501;
vl adj[mx];
vl vis(mx),mt(mx,-1);

bool dfs(ll u){
    if(vis[u]) return 0;
    vis[u]=1;
    for(ll v:adj[u]){
        if(mt[v]==-1 or dfs(mt[v])){
            mt[v]=u;
            return 1;
        }
    }
    return 0;
}
void solve(){
    cin>>n>>m>>k;
    forl(i,0,k){
        ll a,b;
        cin>>a>>b,a--,b--;
        adj[a].pb(b);
    }
    int res=0;
    forl(i,0,n){
        fill(all(vis),0);
        res+=dfs(i);
    }
    cout<<res<<endl;
    forl(i,0,m){
        if(mt[i]!=-1) cout<<mt[i]+1<<" "<<i+1<<endl;
    }
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}