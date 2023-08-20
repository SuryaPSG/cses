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
    vll vec(n);
    forl(i,0,n){
        ll s,f;
        cin>>s>>f;
        vec[i]={s,f};
    }
    sort(all(vec),[](pll &a,pll &b){
        return a.se<b.se or (a.se==b.se and a.fi<b.fi);
    });
    // forl(i,0,n){
    //     cout<<vec[i].fi<<" "<<vec[i].se<<endl;
    // }
    ll i=0,j=1,res=1;
    while(j<n){
        if(vec[j].fi>= vec[i].se){
            res++;
            i=j;
        }
        j++;
    }
    cout<<res<<endl;
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}