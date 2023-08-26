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
    ll dp[n+1][2];
    memset(dp,0,sizeof(dp));
    dp[1][0]=dp[1][1]=1;
    forl(i,2,n+1){
        dp[i][0]=(4*dp[i-1][0]+dp[i-1][1])%md;
        dp[i][1]=(dp[i-1][0]+2*dp[i-1][1])%md;
    }
    cout<<(dp[n][0]+dp[n][1])%md<<endl;
}

int main()
{
    DONTSYNC;
    TEST
    solve();
    return 0;
}