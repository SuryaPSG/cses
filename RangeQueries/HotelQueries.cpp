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
 
void build(ll idx,ll left,ll right){
    if(left==right){
        seg[idx]=a[left];
        return;
    }
    ll m=(left+right)/2;
    build(2*idx+1,left,m);
    build(2*idx+2,m+1,right);
    seg[idx]=max(seg[2*idx+1],seg[2*idx+2]);
}


void query(ll idx, ll left,ll right,ll val){
    if(left==right){
        seg[idx]-=val;
        cout<<left+1<<endl;
        return;
    }
    ll m=(left+right)>>1;
    if(seg[2*idx+1]>=val) query(2*idx+1,left,m,val);
    else query(2*idx+2,m+1,right,val);
    seg[idx]=max(seg[2*idx+1],seg[2*idx+2]);
}
 
 
void solve(){
    ll n,q;
    cin>>n>>q;
    forl(i,0,n) cin>>a[i];
    build(0,0,n-1);
    forl(i,0,q){
        ll v;
        cin>>v;
        if(seg[0]<v) cout<<"0"<<endl;
        else query(0,0,n-1,v);
    }
}
 
int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}