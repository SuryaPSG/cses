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


void solve(){
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,pll>> Edge;
    forl(i,0,m){
        ll u,v,w;
        cin>>u>>v>>w;
        Edge.pb({w,{u,v}});
    }
    vl dist(n+1,0x3f3f3f3f3f3f3f3f);
    vl par(n+1,0);
    ll p=-1;
    dist[1]=0;
    dist[0]=0;
    for(ll i=0;i<n and p;i++){
        p=0;
        forl(j,0,m){
            ll w=Edge[j].fi;
            ll u=Edge[j].se.fi;
            ll v=Edge[j].se.se;
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                par[v]=u;
                p=v;
            }
        }
    }
    if(p==0) {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    forl(i,1,n+1) p=par[p];
    vl vec;
    for(ll x=p;;x=par[x]){
        vec.pb(x);
        if(x==p and vec.size()>1) break;
    }
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