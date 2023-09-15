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
const ll md=1e9+7;

vvl matrix_multiplication(vvl &a,vvl &b,ll n){
    vvl res(n,vl(n,0));
    forl(i,0,n){
        forl(j,0,n){
            forl(k,0,n){
                res[i][j]+=a[i][k]*b[k][j];
                res[i][j]%=md;
            }
        }
    }
    return res;
}

vvl powmod(vvl a,ll y){
    ll n=a.size();
    vvl res(n,vl(n,0));
    forl(i,0,n) res[i][i]=1;
    while(y){
        if(y&1) res=matrix_multiplication(res,a,n);
        a=matrix_multiplication(a,a,n);
        y>>=1;
    }
    return res;
}

void solve(){
    ll n;
    cin>>n;
    if(n<=6){
        cout<<((ll)pow(2,n-1))<<endl;
        return;
    }
    vvl a={
        {1,1,1,1,1,1},
        {1,0,0,0,0,0},
        {0,1,0,0,0,0},
        {0,0,1,0,0,0},
        {0,0,0,1,0,0},
        {0,0,0,0,1,0}
    };
    a=powmod(a,n-6);
    ll res=0;
    res=(res+a[0][0]*32)%md;
    res=(res+a[0][1]*16)%md;
    res=(res+a[0][2]*8)%md;
    res=(res+a[0][3]*4)%md;
    res=(res+a[0][4]*2)%md;
    res=(res+a[0][5])%md;
    cout<<res<<endl;
    return;
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}