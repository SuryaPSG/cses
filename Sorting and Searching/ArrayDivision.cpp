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

int issf(vl &vec,ll c){
    ll p=1,s=0,n=vec.size();
    forl(i,0,n){
        if(s+vec[i]>c){
            p++;
            s=vec[i];
        }
        else s+=vec[i];
    }
    return p;
}

void solve(){
    ll n,k;
    cin>>n>>k;
    vl vec(n);
    forl(i,0,n) cin>>vec[i];
    ll l=*max_element(all(vec)),r=accumulate(all(vec),0LL),res=r;
    while(l<=r){
        ll m=l+(r-l)/2;
        ll p=issf(vec,m);
        if(p<=k){
            res=m;
            r=m-1;
        }
        else l=m+1;
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