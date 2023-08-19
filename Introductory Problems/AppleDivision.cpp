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

void util(vl &vec, ll idx, ll s1,ll s2,ll &res){
    ll n=vec.size();
    if(idx==n){
        res=min(res,abs(s1-s2));
        return;
    }
    util(vec,idx+1,s1+vec[idx],s2,res);
    util(vec,idx+1,s1,s2+vec[idx],res);
}

void solve(){
    ll n;
    cin>>n;
    vl vec(n);
    forl(i,0,n) cin>>vec[i];
    ll res=LLONG_MAX;
    util(vec,0,0,0,res);
    cout<<res<<endl;
}

int main()
{
    DONTSYNC;
    //TEST
    solve();
    return 0;
}