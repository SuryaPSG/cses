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
    ll n,m;
    cin>>n>>m;
    vl vec(n);
    forl(i,0,n) cin>>vec[i];
    vvl dp(n,vl(m+1,0));
    if(vec[0]==0) dp[0]=vl(m+1,1);
    else dp[0][vec[0]]=1;
    forl(i,1,n){
        if(vec[i]==0){
            forl(j,1,m+1){
                dp[i][j]+=dp[i-1][j];
                if(j-1>0) dp[i][j]+=dp[i-1][j-1];
                if(j+1<=m) dp[i][j]+=dp[i-1][j+1];
                dp[i][j]%=md;
            }
            
        }
        else{
            dp[i][vec[i]]+=dp[i-1][vec[i]];
            if(vec[i]-1>0) dp[i][vec[i]]+=dp[i-1][vec[i]-1];
            if(vec[i]+1<=m) dp[i][vec[i]]+=dp[i-1][vec[i]+1];
            dp[i][vec[i]]%=md;
        }
    }
    ll res=0;
    forl(i,1,m+1) res=(res+dp[n-1][i])%md;
    cout<<res<<endl;
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}