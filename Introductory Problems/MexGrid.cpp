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

vvl res;
void mxgrid(ll r,ll c){
    ll i=ceil(log2(r+1))-1,j=ceil(log2(c+1))-1;
    int i2=(i==-1?0:(1<<i)),j2=(j==-1?0:(1<<j));
    if(i2==j2) res[r][c] = res[r-i2][c-j2];
    else if(i2>j2) res[r][c] = res[r-i2][c]+i2;
    else res[r][c] = res[r][c-j2]+j2;
}

void solve(){
    ll n;
    cin>>n;
    res=vvl(n,vl(n));
    forl(i,0,n){
        forl(j,0,n){
            mxgrid(i,j);
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    DONTSYNC;
    //TEST
    solve();
    return 0;
}