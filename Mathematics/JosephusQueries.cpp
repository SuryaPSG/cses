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

ll josephus(ll n,ll k){
    if(n==1) return 1;
    if(k<=(n+1)/2){
        if(2*k<=n) return 2*k;
        else return (2*k)%n;
    }
    ll t=josephus(n/2,k-(n+1)/2);
    if(n&1) return 2*t+1;
    return 2*t-1;
}

void solve(){
    ll n,k;
    cin>>n>>k;
    cout<<josephus(n,k)<<endl;
}

int main()
{
    DONTSYNC;
    TEST
    solve();
    return 0;
}