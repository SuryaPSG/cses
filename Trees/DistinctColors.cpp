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
ll n,t=0;
vl fen(mx),a(mx),lend(mx),tour(mx),ans(mx);
vvl adj(mx);
void update(int val,int idx){
    ++idx;
    while(idx<=n){
        fen[idx]+=val;
        idx+=idx&-idx;
    }
}
 
ll sum(int idx){
    ++idx;
    ll res=0;
    while(idx>0){
        res+=fen[idx];
        idx-=idx&-idx;
    }
    return res;
}
void dfs(ll u,ll p=0){
    lend[u]=t;
    for(ll v:adj[u]){
        if(v!=p){
            dfs(v,u);
        }
    }
    tour[t]=u;
    t++;
}
void solve(){
    cin>>n;
    forl(i,1,n+1) cin>>a[i];
    forl(i,0,n-1){
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1);
    mll mp;
    forl(i,0,n){
        if(mp.count(a[tour[i]])){
            update(-1,mp[a[tour[i]]]);
        }
        mp[a[tour[i]]]=i;
        update(1,i);
        ans[tour[i]]=sum(i)-sum(lend[tour[i]]-1);
    }
    forl(i,1,n+1) cout<<ans[i]<<" ";
}

int main()
{
    DONTSYNC;
    //TEST
    solve();
    return 0;
}