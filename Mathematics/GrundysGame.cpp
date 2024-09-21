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
const ll mx=1e6;
const ll limit=2001;
vl dp(mx);
ll mex(vl &vec){
    sll s{vec.begin(),vec.end()};
    forl(i,0,mx){
        if(!s.count(i)) return i;
    }
    return mx;
}
void pre_calc(){
    dp[0]=dp[1]=dp[2]=0;
    for(int i=3;i<=limit;i++){
        vl vec;
        for(int j=1;2*j<i;j++){
            vec.pb(dp[i-j]^dp[j]);
        }
        dp[i]=mex(vec);
    }
}

void solve(){
    ll n;
    cin>>n;
    if(n>=2000) cout<<"first"<<endl;
    else if(dp[n]) cout<<"first"<<endl;
    else cout<<"second"<<endl;
    return;
}

int main()
{
    DONTSYNC;
    pre_calc();
    TEST
    solve();
    return 0;
}