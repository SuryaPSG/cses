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

multiset<ll> low;
multiset<ll> high;
ll sl=0,su=0;

void ins(ll val,ll k){
    if(*low.rbegin()>=val){
        low.insert(val);
        sl+=val;
        if(low.size()>(k+1)/2){
            ll mx=*low.rbegin();
            high.insert(*low.rbegin());
            su+=mx;
            low.erase(low.find(*low.rbegin()));
            sl-=mx;
        }
    }
    else{
        high.insert(val);
        su+=val;
        if(high.size()>k/2){
            ll mx=*high.begin();
            low.insert(mx);
            sl+=mx;
            high.erase(high.find(mx));
            su-=mx;
        }
    }
}

void erase(ll val){
    if(high.count(val)) high.erase(high.find(val)),su-=val;
    else low.erase(low.find(val)),sl-=val;
    if(low.empty()){
        ll mx=*high.begin();
        low.insert(*high.begin());
        sl+=mx;
        high.erase(high.find(*high.begin()));
        su-=mx;
    }
}

void solve(){
    ll n,k;
    cin>>n>>k;
    vl vec(n);
    forl(i,0,n) cin>>vec[i];
    low.insert(vec[0]);
    sl+=vec[0];
    forl(i,1,k) ins(vec[i],k);
    cout<<su-sl+((k%2==0)?(0):(*low.rbegin()))<<" ";
    forl(i,k,n){
        if (k == 1) {
			ins(vec[i],k);
			erase(vec[i - k]);
		} else {
			erase(vec[i - k]);
			ins(vec[i],k);
		}
        cout<<su-sl+((k%2==0)?(0):(*low.rbegin()))<<" ";
    }
    cout<<endl;
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}