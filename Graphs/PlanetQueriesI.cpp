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
const ll Log=30;
const ll N=2e5+1;

ll up[N][Log];

ll binary_lift(ll u,ll k){
    forl(i,0,Log){
        if((1<<i)&k) u=up[u][i];
    }
    return u;
}

void solve(){
    ll n,q;
    cin>>n>>q;

    forl(i,1,n+1) cin>>up[i][0];

    forl(i,1,Log){
        forl(j,1,n+1){
            up[j][i]=up[up[j][i-1]][i-1];
        }
    }

    forl(i,0,q){
        ll u,k;
        cin>>u>>k;
        cout<<binary_lift(u,k)<<endl;
    }
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}