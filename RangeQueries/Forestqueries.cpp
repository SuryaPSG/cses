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

void solve(){
    ll n,q;
    cin>>n>>q;
    vector<string> vec(n);
    forl(i,0,n) cin>>vec[i];
    ll dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    forl(i,1,n+1){
        forl(j,1,n+1){
            if(vec[i-1][j-1]=='*') dp[i][j]+=1;
            dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
        }
    }
    forl(i,0,q){
        ll sx,sy,tx,ty;
        cin>>sx>>sy>>tx>>ty;
        ll u=dp[sx-1][ty];
        ll v=dp[tx][sy-1];
        ll w=dp[sx-1][sy-1];
        cout<<dp[tx][ty]-u-v+w<<endl;
    }
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}