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

void solve(){
    ll n;
    cin>>n;
    vector<pair<pll,ll>> vec(n);
    sll st;
    forl(i,0,n){
        ll u,v;
        cin>>u>>v;
        vec[i]={{u,v},i};
        st.insert(i+1);
    }
    sort(all(vec),[](pair<pll,ll> &a,pair<pll,ll> &b){
        return a.fi.fi<b.fi.fi or(a.fi.fi==b.fi.fi and a.fi.se<b.fi.se);
    });
    priority_queue<pll,vll,greater<pll>> Q;
    vector<int> res(n);
    ll mx=0;
    forl(i,0,n){
        while(!Q.empty() and vec[i].fi.fi>Q.top().fi){
            pll p=Q.top();
            Q.pop();
            st.insert(p.se);
        }
        auto it=st.begin();
        res[vec[i].se]=*it;
        mx=max(mx,*it);
        st.erase(it);
        Q.push({vec[i].fi.se,res[vec[i].se]});
    }
    cout<<mx<<endl;
    forl(i,0,n) cout<<res[i]<<" ";
    cout<<endl;
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}