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
const ll mx=1e6;

ll least_prime_factor[mx+5];
ll mobius[mx+5];

void pre_calc(){
    for(ll i=2;i<=mx;i++){
        if(!least_prime_factor[i]){
            for(ll j=i;j<=mx;j+=i) if(!least_prime_factor[j]) least_prime_factor[j]=i;
        }
    }
}

void calc_mobius(){
    mobius[1]=1;
    forl(i,2,mx+1){
        if(least_prime_factor[i/least_prime_factor[i]]==least_prime_factor[i]) mobius[i]=0;
        else mobius[i]=-mobius[i/least_prime_factor[i]];
    }
}

void solve(){
    pre_calc();
    calc_mobius();
    ll n,mx=0;
    cin>>n;
    umll mp;
    forl(i,0,n){
        ll v;
        cin>>v;
        mp[v]++;
        mx=max(mx,v);
    }
    ll res=0;
    forl(i,1,mx+1){
        if(mobius[i]==0) continue;
        ll d=0;
        for(ll j=i;j<=mx;j+=i){
            d+=mp[j];
        }
        res+=(d*(d-1)/2)*mobius[i];
    }
    cout<<res<<endl;
}

int main()
{
    DONTSYNC;
    //TEST
    solve();
    return 0;
}