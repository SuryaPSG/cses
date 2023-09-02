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

vl par;

ll findpar(ll u){
    if(u==par[u]) return u;
    return par[u]=findpar(par[u]);
}

ll kruskals(vector<pair<ll,pll>> &edges,ll m){
    sort(all(edges));
    ll res=0;
    forl(i,0,m){
        ll u=findpar(edges[i].se.fi);
        ll w=edges[i].fi;
        ll v=findpar(edges[i].se.se);
        if(u==v) continue;
        else{
            res+=w;
            par[v]=par[u];
        }
    }
    return res;
}

void solve(){
    ll n,m;
    cin>>n>>m;
    par=vl(n+1);
    forl(i,1,n+1) par[i]=i;
    vector<pair<ll,pll>> edges(m);
    forl(i,0,m){
        ll u,v,w;
        cin>>u>>v>>w;
        edges[i]={w,{u,v}};
    }
    ll res=kruskals(edges,m);
    forl(i,1,n+1){
        par[i]=findpar(par[i]);
    }
    forl(i,2,n+1) if(par[i]!=par[i-1]){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    cout<<res<<endl;
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}