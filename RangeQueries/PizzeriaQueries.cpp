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
vl a;
class SegmentTree{
    public:
    int n;
    vl t;
    SegmentTree(){}
    SegmentTree(int n){
        this->n=n;
        t=vl(4*n+1,INF);
    }
    void update(int i,int val,int idx,int left,int right){
        if(left==right){
            t[idx]=val;
            return;
        }
        ll m=(left+right)>>1;
        if(i<=m) update(i,val,2*idx,left,m);
        else update(i,val,2*idx+1,m+1,right);
        t[idx]=min(t[2*idx],t[2*idx+1]);
    }
    void update(int i,int val) {
        update(i,val,1,1,n);
    }
    ll query(int l,int r,int idx,int left,int right){
        if(l<=left and right<=r) return t[idx];
        if(l>right or r<left) return INF;
        ll m=(left+right)>>1;
        return min(query(l,r,2*idx,left,m),query(l,r,2*idx+1,m+1,right));
    }
    ll query(int l,int r){
        return query(l,r,1,1,n);
    }
};
SegmentTree up,down;
void pull(int i){
    up.update(i,a[i]+i);
    down.update(i,a[i]-i);
}
void solve(){
    ll n,q;
    cin>>n>>q;
    a=vl(n+1);
    up=SegmentTree(n+1);
    down=SegmentTree(n+1);
    forl(i,1,n+1){
        cin>>a[i];
    }
    forl(i,1,n+1) pull(i);
    forl(i,0,q){
        ll t;
        cin>>t;
        if(t==1){
            ll k,x;
            cin>>k>>x;
            a[k]=x;
            pull(k);
        }
        else{
            ll k;
            cin>>k;
            ll l=up.query(k,n)-k;
            ll d=down.query(1,k)+k;
            cout<<min(l,d)<<endl;
        }
    }
}

int main()
{
    DONTSYNC;
    //TEST
    solve();
    return 0;
}