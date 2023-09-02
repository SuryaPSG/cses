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
const ll N=2e5+1;
ll up[N];
ll dist_to_cycle_start[N],vis[N];
queue<ll> path;

void dfs(ll u,ll &d){
    path.push(u);
    if(vis[u]){
        d+=dist_to_cycle_start[u];
        return;
    }
    vis[u]=1;
    d++;
    dfs(up[u],d);
}


void solve(){
    ll n;
    cin>>n;
    memset(up,0,sizeof(up));
    memset(dist_to_cycle_start,0,sizeof(dist_to_cycle_start));
    memset(vis,0,sizeof(vis));

    forl(i,1,n+1) cin>>up[i];

    forl(i,1,n+1) if(!vis[i]){
        ll d=0;
        dfs(i,d);
        ll f=1;
        while(!path.empty()){
            if(path.back()==path.front()) f=0;
            dist_to_cycle_start[path.front()]=d;
            d-=f;
            path.pop();
        }
    }

    forl(i,1,n+1) cout<<dist_to_cycle_start[i]<<" ";
    cout<<endl;
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}