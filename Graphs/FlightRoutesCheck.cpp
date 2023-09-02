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
vl disc,low;
ll t;
stack<ll> st;
vl stackmember;
ll f=-1;

void dfs(ll u){
    disc[u]=low[u]=++t;
    st.push(u);
    stackmember[u]=1;
    for(ll v:adj[u]){
        if(!disc[v]){
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(stackmember[v]) low[u]=min(low[u],disc[v]);
    }
    if(low[u]==disc[u]){
        if(f!=-1){
            cout<<"NO"<<endl;
            cout<<f<<" "<<u<<endl;
            exit(0);
        }
        while(st.top()!=u){
            ll w=st.top();
            st.pop();
            stackmember[w]=0;
        }
        ll w=st.top();
        stackmember[w]=0;
        if(f==-1) f=w;
        st.pop();
    }
    return;
}


void solve(){
    ll n,m;
    cin>>n>>m;
    adj=vvl(n+1);
    disc=vl(n+1);
    low=vl(n+1);
    stackmember=vl(n+1);
    t=0;
    forl(i,0,m){
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
    }
    forl(i,1,n+1){
        if(!disc[i]){
            dfs(i);
        }
    }
    cout<<"YES"<<endl;
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}