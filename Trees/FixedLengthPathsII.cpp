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
int n,a,b;
vi adj[mx];
int sub[mx],processed[mx],cnt[mx];
ll ans=0;
int mx_depth=0;
vi fen(mx);
void update(int val,int idx){
    ++idx;
    while(idx<=n){
        fen[idx]+=val;
        idx+=idx&-idx;
    }
}
 
ll sum(int idx){
    ll res=0;
    ++idx;
    while(idx>0){
        res+=fen[idx];
        idx-=idx&-idx;
    }
    return res;
}
 
ll pres(ll l,ll r){
    return sum(r)-sum(l-1);
}
 
int subtree(int u,int p=0){
    sub[u]=1;
    for(int v:adj[u]){
        if(!processed[v] and v!=p){
            sub[u]+=subtree(v,u);
        }
    }
    return sub[u];
}

int centeroid(int d,int u,int p=0){
    for(ll v:adj[u]){
        if(!processed[v] and v!=p and sub[v]>=d){
            return centeroid(d,v,u);
        }
    }
    return u;
}
 
void get_cnt(int u,int p, bool f,int d=1){
    if(d>b) return;
    mx_depth=max(mx_depth,d);
    if(f) update(1,d);
    else ans+=pres(max(0,a-d),b-d);
    for(ll v:adj[u]){
        if(v!=p and !processed[v]) get_cnt(v,u,f,d+1);
    }
}
 
void centroid_decom(int u){
    ll c=centeroid(subtree(u)>>1,u);
    processed[c]=1;
    mx_depth=0;
    for(ll v:adj[c]){
        if(!processed[v]){
            get_cnt(v,c,false);
            get_cnt(v,c,true);
        }
    }
    forl(i,1,mx_depth+1){
        update(-pres(i,i),i);
    }
    for(ll v:adj[c]){
        if(!processed[v]){
            centroid_decom(v);
        }
    }
}

void solve(){
    cin>>n>>a>>b;
    update(1,0);
    forl(i,0,n-1){
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    centroid_decom(1);
    cout<<ans<<endl;
}
 
int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}