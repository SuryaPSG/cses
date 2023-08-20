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
    ll n,m;
    cin>>n>>m;
    vl vec(n+1,0),idx(n+1,0);
    forl(i,1,n+1){
        cin>>vec[i];
        idx[vec[i]]=i;
    }
    ll res=1,i=1;
    while(i<=n){
        if(idx[i]<idx[i-1]){
            res++;
        }
        i++;
    }
    while(m--){
        ll x,y;
        cin>>x>>y;
        ll r=vec[x],s=vec[y];
        swap(vec[x],vec[y]);
        if(idx[r-1]<=idx[r] and idx[r-1]>y) res++;
        if(idx[r-1]>idx[r] and idx[r-1]<=y) res--;
        if(idx[r]<=idx[r+1] and y>idx[r+1]) res++;
        if(idx[r]>idx[r+1] and y<=idx[r+1]) res--;
        idx[r]=y;
        if(idx[s-1]<=idx[s] and idx[s-1]>x) res++;
        if(idx[s-1]>idx[s] and idx[s-1]<=x) res--;
        if(idx[s]<=idx[s+1] and x>idx[s+1]) res++;
        if(idx[s]>idx[s+1] and x<=idx[s+1]) res--;
        idx[s]=x;
        cout<<res<<endl;
    }
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}