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
    ll n;
    cin>>n;
    const ll md=1e9+7;
    vector<string> g(n);
    forl(i,0,n) cin>>g[i];
    if(g[0][0]=='*' or g[n-1][n-1]=='*'){
        cout<<"0"<<endl;
        return;
    }
    ll dp[n][n];
    memset(dp,0,sizeof(dp));
    forl(i,0,n){
        forl(j,0,n){
            if(i==0 and j==0) dp[i][j]=1;
            else if(i==0){
                if(g[i][j]=='*') dp[i][j]=0;
                else dp[i][j]=dp[i][j-1];
            }
            else if(j==0){
                if(g[i][j]=='*') dp[i][j]=0;
                else dp[i][j]=dp[i-1][j];
            }
            else{
                if(g[i][j]=='*') dp[i][j]=0;
                else dp[i][j]=(dp[i-1][j]+dp[i][j-1])%md;
            }
        }
    }
    cout<<dp[n-1][n-1]<<endl;
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}