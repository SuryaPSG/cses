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
const ll MAX=1e6;
const ll md=1e9+7;
ll fac[MAX+5],i_fac[MAX+5];

ll powmod(ll x,ll n){
    ll res=1;
    x%=md;
    while(n){
        if(n&1) res=res*x%md;
        x=x*x%md;
        n>>=1;
    }
    return res;
}

ll modinv(ll x){
    return powmod(x,md-2);
}

void pre_calc(){
    fac[0]=1;
    fac[1]=1;
    i_fac[1]=1;
    i_fac[0]=1;
    forl(i,2,MAX+1){
        fac[i]=(fac[i-1]*i)%md;
        i_fac[i]=modinv(fac[i]);
    }
}

void solve(){
    string str;
    cin>>str;
    vl vec(26,0);
    ll n=str.length();
    forl(i,0,n) vec[str[i]-'a']++;
    ll res=fac[n];
    forl(i,0,26){
        res=(res*i_fac[vec[i]])%md;
    }
    cout<<res<<endl;
}

int main()
{
    DONTSYNC;
    pre_calc();
    //TEST
    solve();
    return 0;
}