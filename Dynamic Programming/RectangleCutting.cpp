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

ll dp[501][501];

ll solve(ll a,ll b){
    if(dp[a][b]!=-1) return dp[a][b];
    if(a==b) return dp[a][b]=0;
    if(a==1 or b==1) return dp[a][b]=((a==1)?(b-1):(a-1));
    ll res=INT32_MAX;
    forl(i,1,a) res=min(res,solve(i,b)+solve(a-i,b)+1);
    forl(i,1,b) res=min(res,solve(a,i)+solve(a,b-i)+1);
    return dp[a][b]=res;
}

void solve(){
    ll a,b;
    cin>>a>>b;
    memset(dp,-1,sizeof(dp));
    cout<<solve(a,b)<<endl;
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}