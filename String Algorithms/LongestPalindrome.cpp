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

vl manachers(string s){
    string str="#";
    for(char c:s){
        str.pb(c);
        str.pb('#');
    }

    ll n=str.length();
    vl z(n);
    for(ll i=1,l=0,r=0;i<n;i++){
        if(i<r) z[i]=min(r-i,z[2*l-i]);
        while(i+z[i]+1<n and i-z[i]-1>=0 and str[i+z[i]+1]==str[i-z[i]-1]) ++z[i];
        if(i+z[i]>r){
            l=i;
            r=i+z[i];
        }
    }
    return z;
}

void solve(){
    string str;
    cin>>str;
    vl z=manachers(str);
    ll idx=0,res=1,n=2*str.length()+1;
    forl(i,1,n){
        if(z[i]>res){
            res=z[i];
            idx=i;
        }
    }
    cout<<str.substr(idx/2-res/2,res)<<endl;
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}