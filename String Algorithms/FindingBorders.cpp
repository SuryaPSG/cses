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

vl compute_lps(string str){
    ll n=str.length();
    vl vec(n);
    ll len=0,i=1;
    while(i<n){
        if(str[i]==str[len]){
            vec[i++]=++len;
        }
        else{
            if(len!=0) len=vec[len-1];
            else vec[i++]=0;
        }
    }
    return vec;
}

void solve(){
    string str;
    cin>>str;

    ll n=str.length();

    vl vec=compute_lps(str);

    sll st;
    ll c=vec[n-1];
    while(c>0){
        st.insert(c);
        c=vec[c-1];
    }
    for(ll i:st) cout<<i<<" ";
    cout<<endl;
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}