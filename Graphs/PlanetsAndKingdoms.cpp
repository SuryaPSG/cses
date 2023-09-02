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
vl disc,low,king,stackmember;
ll t,k=1;
stack<ll> st;

void dfs(ll u){
    low[u]=disc[u]=++t;
    st.push(u);
    stackmember[u]=true;
    for(ll v:adj[u]){
        if(!disc[v]){
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(stackmember[v]) low[u]=min(low[u],disc[v]);
    }
    if(low[u]==disc[u]){
        while(st.top()!=u){
            ll w=st.top();
            st.pop();
            king[w]=k;
            stackmember[w]=false;
        }
        ll w=st.top();
        st.pop();
        king[w]=k;
        stackmember[w]=false;
        k++;
    }
}

void solve(){
    ll n,m;
    cin>>n>>m;
    adj=vvl(n+1);
    disc=vl(n+1);
    low=vl(n+1);
    stackmember=vl(n+1);
    king=vl(n+1);
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
    k--;
    cout<<k<<endl;
    forl(i,1,n+1) cout<<king[i]<<" ";
    cout<<endl;
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}