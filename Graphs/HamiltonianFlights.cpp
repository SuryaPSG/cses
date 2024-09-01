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
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll md=1e9+7;
const ll mx = 1<<20;
ll dp[mx][20];
ll adj[20][20];
void solve(){
    ll n,m;
    cin>>n>>m;
    memset(dp,0,sizeof(dp));
    memset(adj,0,sizeof(adj));
    forl(i,0,m){
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a][b]++;
    }
    dp[1][0]=1;
    for(ll mask=2;mask<(1<<n);mask++){
        if(mask>>(n-1)&1 and mask!=(1<<n)-1) continue;
        forl(j,0,n){
            if(mask>>j&1){
                ll rem = mask ^ (1<<j);
                forl(k,0,n){
                    if(rem>>k&1 and adj[k][j]){
                        dp[mask][j]+=adj[k][j]*dp[rem][k];
                        dp[mask][j]%=md;
                    }
                }
            }
        }
    }
    cout<<dp[(1<<n)-1][n-1]<<endl;
}

int main()
{
    DONTSYNC;
    //TEST
    solve();
    return 0;
}