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
const ll mx=2e5;

ll seg[4*mx];
ll a[mx];
vl dp(mx,0);

void build(ll idx,ll left, ll right){
    if(left==right){
        seg[idx]=dp[left];
        return;
    }
    ll m=(left+right)>>1;
    build(2*idx+1,left,m);
    build(2*idx+2,m+1,right);
    seg[idx]=max(seg[2*idx+1],seg[2*idx+2]);
}
 
ll maxval(ll idx,ll left, ll right,ll l,ll r){
    if(l<=left and right<=r) return seg[idx];
    if(left>r or right<l) return 0;
    ll m=(left+right)>>1;
    return max(maxval(2*idx+1,left,m,l,r),maxval(2*idx+2,m+1,right,l,r));
}

void pointUpdate(ll idx, ll left,ll right,ll node,ll val){
    if(left==right){
        seg[idx]=val;
        return;
    }
    ll m=(left+right)>>1;
    if(node>=left and node<=m) pointUpdate(2*idx+1,left,m,node,val);
    else pointUpdate(2*idx+2,m+1,right,node,val);
    seg[idx]=max(seg[2*idx+1],seg[2*idx+2]);
}

void solve(){
    ll n;
    cin>>n;
    forl(i,0,n) cin>>a[i];

    vll vec(n);

    forl(i,0,n) vec[i]={a[i],i};
    sort(all(vec));

    vl rt(n),lt(n);
    vi st;
    for(ll i=n-1;i>=0;i--){
        while(!st.empty() and a[i]>a[st.back()]) st.pop_back();
        if(st.empty()) rt[i]=n;
        else rt[i]=st.back();
        st.pb(i);
    }
    st.clear();
    forl(i,0,n){
        while(!st.empty() and a[i]>a[st.back()]) st.pop_back();
        if(st.empty()) lt[i]=-1;
        else lt[i]=st.back();
        st.pb(i);
    }

    build(0,0,n-1);
    ll res=0;
    forl(i,0,n){
        int idx=vec[i].se;
        ll ll = lt[idx], rr= rt[idx];
        dp[idx]= maxval(0,0,n-1,ll+1,rr-1)+1;
        pointUpdate(0,0,n-1,idx,dp[idx]);
        res=max(res,dp[idx]);
    }
    cout<<res<<endl;
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}