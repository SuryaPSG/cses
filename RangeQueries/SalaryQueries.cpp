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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset= tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;

void solve(){
    ll n,q;
    cin>>n>>q;
    vl vec(n);
    forl(i,0,n) cin>>vec[i];
    oset<pll> st;
    forl(i,0,n) st.insert({vec[i],i+1});
    forl(i,0,q){
        char c;
        cin>>c;
        if(c=='?'){
            ll u,v;
            cin>>u>>v;
            cout<<st.order_of_key({v,INF})-st.order_of_key({u-1,INF})<<endl;
        }
        else{
            ll u,k;
            cin>>u>>k;
            st.erase(st.lower_bound({vec[u-1],0}));
            vec[u-1]=k;
            st.insert({k,u});
        }
    }
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}