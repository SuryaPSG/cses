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
    ll n,s;
    cin>>n>>s;
    vi pr(n),pg(n);
    forl(i,0,n) cin>>pr[i];
    forl(i,0,n) cin>>pg[i];
    vvi dp(n+1,vi(s+1,0));
    forl(i,1,n+1){
        forl(j,0,s+1){
            if(j>=pr[i-1]) dp[i][j]=max(dp[i-1][j],pg[i-1]+dp[i-1][j-pr[i-1]]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[n][s]<<endl;
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}