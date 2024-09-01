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
struct {
    ll lz=0,s=0;
    bool lz2=0;
} seg[4*mx+5];
vl a(mx);
void app(int i,ll left,ll right,ll val,bool lz2){
    if(lz2){
        seg[i].s=0;
        seg[i].lz=0;
        seg[i].lz2=1;
    }
    seg[i].s+=(right-left+1)*val;
    seg[i].lz+=val;
}
void psh(int i,int left,int mid,int right){
    app(2*i+1,left,mid,seg[i].lz,seg[i].lz2);
    app(2*i+2,mid+1,right,seg[i].lz,seg[i].lz2);
    seg[i].lz=0;
    seg[i].lz2=0;
}
void update(int i,int p,int left,int right,ll val){
    if(left==right){
        seg[i].s=val;
        return;
    }
    ll m=(left+right)>>1;
    psh(i,left,m,right);
    if(p<=m) update(2*i+1,p,left,m,val);
    else update(2*i+2,p,m+1,right,val);
    seg[i].s=seg[2*i+1].s+seg[2*i+2].s;
}
void rangeUpdate(int i,int l,int r,int left,int right,int val,bool lz){
    if(l<=left and right<=r){
        app(i,left,right,val,lz);
        return;
    }
    ll m=(left+right)>>1;
    psh(i,left,m,right);
    if(l<=m) rangeUpdate(2*i+1,l,r,left,m,val,lz);
    if(m<r) rangeUpdate(2*i+2,l,r,m+1,right,val,lz);
    seg[i].s=seg[2*i+1].s+seg[2*i+2].s;
}
ll query(int i,int left,int right,int l,int r){
    if(l<=left and right<=r) return seg[i].s;
    ll m=(left+right)>>1;
    psh(i,left,m,right);
    ll s=0;
    if(l<=m) s+=query(2*i+1,left,m,l,r);
    if(m<r) s+=query(2*i+2,m+1,right,l,r);
    return s;
}
void solve(){
    ll n,q;
    cin>>n>>q;
    forl(i,0,n){
        cin>>a[i];
        update(0,i,0,n-1,a[i]);
    }
    forl(i,0,q){
        ll t;
        cin>>t;
        if(t==1 or t==2){
            ll a,b,c;
            cin>>a>>b>>c;
            rangeUpdate(0,a-1,b-1,0,n-1,c,t==2);
        }
        else{
            ll a,b;
            cin>>a>>b;
            cout<<query(0,0,n-1,a-1,b-1)<<endl;
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