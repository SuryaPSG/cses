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
vl inor,par;
void topo(queue<ll> &Q){
    while(!Q.empty()){
        ll u=Q.front();
        Q.pop();
        for(ll v:adj[u]){
            inor[v]--;
            if(inor[v]==0){
                par[v]=u;
                if(v!=1) Q.push(v);
            }
        }
    }
}

void solve(){
    ll n,m;
    cin>>n>>m;

    adj=vvl(n+1);
    inor=vl(n+1,0);
    par=vl(n+1,-1);
    forl(i,0,m){
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        inor[v]++;
    }
    queue<ll>Q;
    forl(i,2,n+1) if(inor[i]==0) Q.push(i);
    topo(Q);
    Q.push(1);
    par[n]=-1;
    par[1]=-1;
    topo(Q);

    if(par[n]==-1){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    ll c=n;
    vl vec;
    while(c!=-1){
        vec.pb(c);
        c=par[c];
    }
    reverse(all(vec));
    cout<<vec.size()<<endl;
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