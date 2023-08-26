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
    const ll md=1e9+7;
    ll n;
    cin>>n;
    ll ts=n*(n+1)/2;
    if(ts&1){
        cout<<0<<endl;
        return;
    }
    vl vec;
    forl(i,1,n+1)vec.pb(i);
    ll t=ts/2;
    vvl dp(n+1,vl(t+1,0));
    dp[0][0]=1;
    forl(i,1,n+1){
        forl(j,1,t+1){
            if(j>=vec[i-1]) dp[i][j]=(dp[i-1][j]+dp[i-1][j-vec[i-1]])%md;
            else dp[i][j]=dp[i-1][j]%md;
        }
    }
    cout<<dp[n][t]<<endl;
    return;
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}