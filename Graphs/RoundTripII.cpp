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

vvl adj;
vl vis;
vl cycl;

bool dfs(ll u,ll p){
    if(vis[u]) return vis[u]==1;
    vis[u]=1;
    for(ll v:adj[u]){
        cycl.pb(v);
        if(vis[v]==1 || (!vis[v] and dfs(v,u))) return true;
        cycl.pop_back();
    }
    vis[u]=2;
    return false;
}
void solve(){
    ll n,m;
    cin>>n>>m;
    adj=vvl(n+1);
    vis=vl(n+1);

    forl(i,0,m){
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
    }

    forl(i,1,n+1){
        if(!vis[i]){
            cycl.pb(i);
            if(dfs(i,0)){
                vl ans;
                ans.pb(*cycl.rbegin());
                for(auto it=cycl.rbegin()+1;it!=cycl.rend();it++){
                    ans.pb(*it);
                    if(*cycl.rbegin()==*it) break;
                }
                cout<<ans.size()<<endl;
                reverse(all(ans));
                for(ll v:ans) cout<<v<<" ";
                cout<<endl;
                return;
            }
            cycl.pop_back();
        }
    }

    cout<<"IMPOSSIBLE"<<endl;
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}