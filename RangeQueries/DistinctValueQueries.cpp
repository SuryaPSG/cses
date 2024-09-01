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
class BIT{
    public:
    int n;
    vl t;
    BIT(){}
    BIT(int n){
        this->n=n;
        t=vl(n+1);
    }
    void update(int i,int val){
        while(i<=n){
            t[i]+=val;
            i+=i&-i;
        }
    }
    ll sum(int i){
        ll res=0;
        while(i>0){
            res+=t[i];
            i-=i&-i;
        }
        return res;
    }
    ll rangesum(ll l,ll r){
        return sum(r)-sum(l-1);
    }
};

void solve(){
    ll n,q;
    cin>>n>>q;
    a=vl(n+1);
    BIT f(n+1);
    forl(i,1,n+1){
        cin>>a[i];
    }
    vector<vll> mp(n+1);
    forl(i,0,q){
        int a,b;
        cin>>a>>b;
        mp[a].push_back({b,i});
    }
    mll vis;
    vl res(q,-1);
    for(ll i=n;i>=1;i--){
        if(vis.count(a[i])) f.update(vis[a[i]],-1);
        vis[a[i]]=i;
        f.update(i,1);
        for(auto [r,idx]:mp[i]){
            res[idx]=f.rangesum(i,r);
        }
    }
    for(int i:res) cout<<i<<" ";
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}