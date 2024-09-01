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
vll adj[mx];
vl used(mx),order,in(mx),out(mx);

void dfs(int u){
    while(adj[u].size()){
        auto [v,i]=adj[u].back();
        adj[u].pop_back();
        if(used[i]) continue;
        used[i]=1;
        dfs(v);
    }
    order.pb(u);
}

void solve(){
    ll n,m;
    cin>>n>>m;
    forl(i,0,m){
        ll a,b;
        cin>>a>>b,a--,b--;
        adj[a].pb({b,i});
        in[b]++;
        out[a]++;
    }
    forl(i,1,n-1) if(in[i]!=out[i]){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    if(in[n-1]-1!=out[n-1]){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    if(in[0]!=out[0]-1){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    dfs(0);
    if(order.size()!=m+1){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    reverse(all(order));
    for(ll i:order) cout<<i+1<<" ";
    return;
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}