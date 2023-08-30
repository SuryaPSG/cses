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

ll dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
string str="DRUL";

void solve(){
    ll n,m;
    cin>>n>>m;
    adj=vvl(n+1);
    vis=vl(n+1);

    forl(i,0,m){
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    queue<ll> Q;
    Q.push(1);
    vis[1]=1;
    while(!Q.empty()){
        ll p=Q.front();
        Q.pop();
        if(p==n) break;
        for(ll u:adj[p]){
            if(!vis[u]){
                Q.push(u);
                vis[u]=p;
            }
        }
    }
    if(vis[n]==0){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    vl vec{n};
    while(1){
        ll p=vis[vec.back()];
        if(p==vec.back()) break;
        vec.pb(vis[vec.back()]);
    }
    cout<<vec.size()<<endl;
    reverse(all(vec));
    for(ll i:vec) cout<<i<<" ";
    cout<<endl;
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}