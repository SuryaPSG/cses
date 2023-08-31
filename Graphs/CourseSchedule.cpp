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

    vvl adj(n+1);
    vl inor(n+1);
    forl(i,0,m){
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        inor[v]++;
    }

    queue<ll>Q;
    forl(i,1,n+1) if(inor[i]==0) Q.push(i);

    vl vec;
    while(!Q.empty()){
        ll u=Q.front();
        Q.pop();
        vec.pb(u);
        for(ll v:adj[u]){
            inor[v]--;
            if(inor[v]==0) Q.push(v);
        }
    }
    if(vec.size()!=n){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    for(ll i:vec) cout<<i<<" ";
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}