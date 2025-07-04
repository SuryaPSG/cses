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

    ll n,w;
    cin>>n>>w;

    vl vec(n);
    forl(i,0,n) cin>>vec[i];

    vll dp(1<<n+1);
    dp[0]={1,0};

    forl(i,1,1<<n){
        dp[i]={INF,0};
        forl(j,0,n){
            if((i>>j)&1){
                pll p =dp[i ^(1<<j)];
                if(p.se+vec[j]<=w){
                    p.se+=vec[j];
                }
                else{
                    p.fi+=1;
                    p.se=vec[j];
                }
                dp[i]=min(dp[i],p);
            }
        }
    }
    cout<<dp[(1<<n)-1].fi<<endl;
}

int main()
{
    DONTSYNC;
    //TEST
    solve();
    return 0;
}