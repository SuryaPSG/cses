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
vl col;

ll dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
string str="DRUL";

void solve(){
    ll n,m;
    cin>>n>>m;
    adj=vvl(n+1);
    vis=vl(n+1);
    col=vl(n+1);

    forl(i,0,m){
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    forl(i,1,n+1){
        if(!vis[i]){
            queue<ll> Q;
            Q.push(i);
            vis[i]=1;
            col[i]=0;
            while(!Q.empty()){
                ll p=Q.front();
                Q.pop();
                for(ll u:adj[p]){
                    if(!vis[u]){
                        Q.push(u);
                        vis[u]=1;
                        col[u]=1-col[p];
                    }
                    if(vis[u] and col[u]!=1-col[p]){
                        cout<<"IMPOSSIBLE"<<endl;
                        return;
                    }
                }
            }
        }
    }
    forl(i,1,n+1) cout<<col[i]+1<<" ";
    cout<<endl;
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}