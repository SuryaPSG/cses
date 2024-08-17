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

void solve(){
    ll n,k;
    cin>>n>>k;
    vll vec(n);
    forl(i,0,n) cin>>vec[i].first>>vec[i].second;
    sort(all(vec),[](pll &a,pll &b){
        return a.se<b.se;
    });
    multiset<int> st;
    forl(i,0,k) st.insert(0);
    int res=0;
    forl(i,0,n){
        auto it=st.upper_bound(vec[i].fi);
        if(it==st.begin()) continue;
        st.erase(--it);
        st.insert(vec[i].se);
        res++;
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