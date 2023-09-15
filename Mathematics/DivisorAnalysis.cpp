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
const ll md=1e9+7,md1=1e9+6;

ll powmod(ll x,ll n,ll md){
    ll res=1;
    x%=md;
    while(n){
        if(n&1) res=res*x%md;
        x=x*x%md;
        n>>=1;
    }
    return res;
}

void solve(){
    ll n;
    cin>>n;
    ll N=1,sq=1;
    ll nd=1,sd=1,ndt=1;
    bool f=false;
    forl(i,0,n){
        ll x,k;
        cin>>x>>k;
        nd=(((nd%md)*(k+1)%md)%md+md)%md;
        if(k%2 && !f){
            ndt*=(k+1)/2;
            ndt%=md1;
            f=true;
        }
        else{
            ndt*=(k+1);
            ndt%=md1;
        }
        sd=sd*(powmod(x,k+1,md)-1)%md*powmod(x-1,md-2,md)%md;
        N*=powmod(x,k,md);
        N%=md;
        sq*=powmod(x,k/2,md);
        sq%=md;
    }
    ll pd;
    if(f) pd=powmod(N,ndt,md);
    else pd=powmod(sq,ndt,md);
    cout<<nd<<" "<<sd<<" "<<pd<<endl;
}

int main()
{
    DONTSYNC;
    //TEST
    solve();
    return 0;
}