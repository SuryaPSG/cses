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
    ll n;
    cin>>n;
    ld dp[n+1][8][8];
    ld ans[8][8];
    forl(i,0,8) forl(j,0,8) ans[i][j]=1;
    forl(i,0,8){
        forl(j,0,8){
            memset(dp,0,sizeof(dp));
            dp[0][i][j]=1;
            forl(k,0,n)
            forl(i1,0,8){
                forl(j1,0,8){
                    ll dir=(i1-1>=0)+(j1-1>=0)+(i1+1<=7)+(j1+1<=7);
                    if(i1>0) dp[k+1][i1-1][j1]+=dp[k][i1][j1]/dir;
                    if(j1>0) dp[k+1][i1][j1-1]+=dp[k][i1][j1]/dir;
                    if(i1<7) dp[k+1][i1+1][j1]+=dp[k][i1][j1]/dir;
                    if(j1<7) dp[k+1][i1][j1+1]+=dp[k][i1][j1]/dir;
                }
            }
            forl(i1,0,8){
                forl(j1,0,8) ans[i1][j1]*=(1-dp[n][i1][j1]);
            }
        }
    }
    ld res=0;
    forl(i,0,8) forl(j,0,8) res+=ans[i][j];
    cout<<setprecision(6)<<fixed<<res<<endl;
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}