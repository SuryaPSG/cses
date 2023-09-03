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
const ll mx=2e5+5;
ll a[mx]={0};
ll fen[mx]={0},lazy_fen[mx]={0};
ll N;

void add(ll fen[],ll idx,ll val){
    while(idx<=N){
        fen[idx]+=val;
        idx+=idx&-idx;
    }
}

ll sum(ll fen[],ll idx){
    ll res=0;
    while(idx>0){
        res+=fen[idx];
        idx-=idx&-idx;
    }
    return res;
}

ll prefix_sum(ll idx){
    return sum(fen,idx)*idx-sum(lazy_fen,idx);
}

ll range_sum(ll l,ll r){
    return prefix_sum(r)-prefix_sum(l-1);
}

void RangeUpdate(ll l,ll r,ll val){
    add(fen,l,val);
    add(fen,r+1,-val);
    add(lazy_fen,l,val*(l-1));
    add(lazy_fen,r+1,-val*r);
}

 
 
void solve(){
    ll n,q;
    cin>>n>>q;
    N=n+2;
    forl(i,1,n+1){
        cin>>a[i];
        RangeUpdate(i,i,a[i]);
    }
    forl(i,0,q){
        ll t;
        cin>>t;
        if(t==1){
            ll l,r,val;
            cin>>l>>r>>val;
            RangeUpdate(l,r,val);
        }
        else{
            ll l;
            cin>>l;
            cout<<range_sum(l,l)<<endl;
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