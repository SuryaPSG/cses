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
    vvl vec(n,vl(3));
    forl(i,0,n){
        ll u,v,w;
        cin>>u>>v>>w;
        vec[i]={u,v,w};
    }
    sort(all(vec),[](vl &a,vl &b){
        return a[1]<b[1] or(a[1]==b[1] and a[0]<b[1]);
    });
    ll dp[n];
    dp[0]=vec[0][2];
    mll mp;
    mp[vec[0][1]]=0;
    forl(i,1,n){
        ll t=vec[i][2];
        auto it=mp.lower_bound(vec[i][0]);
        if(it!=mp.begin()){
            it--;
            t+=dp[it->se];
        }
        dp[i]=max(dp[i-1],t);
        mp[vec[i][1]]=i;
    }
    cout<<dp[n-1]<<endl;
}
 
int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}