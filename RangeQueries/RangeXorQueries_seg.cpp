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
const ll mx=2e5+1;
ll a[mx];
ll seg[4*mx];
 
void build(ll idx,ll left, ll right){
    if(left==right){
        seg[idx]=a[left];
        return;
    }
    ll m=(left+right)>>1;
    build(2*idx+1,left,m);
    build(2*idx+2,m+1,right);
    seg[idx]=seg[2*idx+1]^seg[2*idx+2];
}
 
ll xorvalue(ll idx,ll left, ll right,ll l,ll r){
    if(l<=left and right<=r) return seg[idx];
    if(left>r or right<l) return 0;
    ll m=(left+right)>>1;
    return xorvalue(2*idx+1,left,m,l,r)^xorvalue(2*idx+2,m+1,right,l,r);
}
 
 
void solve(){
    ll n,q;
    cin>>n>>q;
    forl(i,0,n) cin>>a[i];
    build(0,0,n-1);
    forl(i,0,q){
        ll l,r;
        cin>>l>>r;
        cout<<xorvalue(0,0,n-1,l-1,r-1)<<endl;
    }
}
 
int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}