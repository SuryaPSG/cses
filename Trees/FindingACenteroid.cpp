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
const ll mx=2e5+5;
ll n;
vvl adj(mx);
vl sub(mx);
ll subtree(ll u,ll p=0){
    sub[u]=1;
    for(ll v:adj[u]){
        if(v!=p){
            sub[u]+=subtree(v,u);
        }
    }
    return sub[u];
}
ll centeroid(ll u,ll p){
    for(ll v:adj[u]){
        if(v!=p and sub[v]*2>n){
            return centeroid(v,u);
        }
    }
    return u;
}
void solve(){
    cin>>n;
    forl(i,0,n-1){
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    subtree(1);
    cout<<centeroid(1,-1);
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}