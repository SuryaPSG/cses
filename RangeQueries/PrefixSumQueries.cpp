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

class Node{
    public:
    ll prefixsum;
    ll suffixsum;
    ll subarraysum;
    ll sum;
    Node(){
        prefixsum=0;
        suffixsum=0;
        subarraysum=0;
        sum=0;
    }
    Node(ll ps,ll ss,ll sas,ll s){
        prefixsum=max(0LL,ps);
        suffixsum=max(0LL,ss);
        subarraysum=max(0LL,sas);
        sum=s;
    }
};
ll a[mx];
Node seg[4*mx];

Node comnine(Node left,Node right){
    ll ps=max(left.prefixsum,left.sum+right.prefixsum);
    ll ss=max(right.suffixsum,right.sum+left.suffixsum);
    ll sum=left.sum+right.sum;
    ll sas=max(max(left.subarraysum,right.subarraysum),left.suffixsum+right.prefixsum);
    return Node(ps,ss,sas,sum);
}

 
void build(ll idx,ll left, ll right){
    if(left==right){
        seg[idx]=Node(a[left],a[left],a[left],a[left]);
        return;
    }
    ll m=(left+right)>>1;
    build(2*idx+1,left,m);
    build(2*idx+2,m+1,right);
    seg[idx]=comnine(seg[2*idx+1],seg[2*idx+2]);
}
 
Node sum(ll idx,ll left, ll right,ll l,ll r){
    if(l<=left and right<=r) return seg[idx];
    if(left>r or right<l) return Node();
    ll m=(left+right)>>1;
    return comnine(sum(2*idx+1,left,m,l,r),sum(2*idx+2,m+1,right,l,r));
}

void pointUpdate(ll idx, ll left,ll right,ll node,ll val){
    if(left==right){
        seg[idx]=Node(val,val,val,val);
        return;
    }
    ll m=(left+right)>>1;
    if(node>=left and node<=m) pointUpdate(2*idx+1,left,m,node,val);
    else pointUpdate(2*idx+2,m+1,right,node,val);
    seg[idx]=comnine(seg[2*idx+1],seg[2*idx+2]);
}
 
 
void solve(){
    ll n,q;
    cin>>n>>q;
    forl(i,0,n) cin>>a[i];
    build(0,0,n-1);
    forl(i,0,q){
        ll t;
        cin>>t;
        if(t==1){
            ll idx,val;
            cin>>idx>>val;
            pointUpdate(0,0,n-1,idx-1,val);
        }
        else{
            ll l,r;
            cin>>l>>r;
            cout<<sum(0,0,n-1,l-1,r-1).prefixsum<<endl;
        }
    }
}
 
int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}