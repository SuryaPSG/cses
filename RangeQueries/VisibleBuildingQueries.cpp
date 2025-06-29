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
    ll L=20;
    ll n,q;
    cin>>n>>q;
    vl vec(n);
    forl(i,0,n) cin>>vec[i];
    vec.push_back(1e9);
    n++;
    vvl up(n,vl(L,n-1));

    vi st;
    for(ll i=n-1;i>=0;i--){
        while(!st.empty() and vec[i]>=vec[st.back()]) st.pop_back();
        up[i][0]=st.empty()?(n-1):st.back();
        st.pb(i);
    }

    forl(i,1,L){
        forl(j,0,n)
        up[j][i] = up[up[j][i-1]][i-1];
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        ll res=1;
        for(ll i=19;i>=0;i--){
            if(up[l][i]<=r){
                res+=1<<(i);
                l=up[l][i];
            }
        }
        cout<<res<<endl;
    }
}

int main()
{
    DONTSYNC;
    //TEST
    solve();
    return 0;
}