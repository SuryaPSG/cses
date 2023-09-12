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

string booth(string s){
    s+=s;
    ll n=s.size();
    ll k=0;
    vl f(n,-1);
    for(ll j=1;j<n;j++){
        ll i=f[j-k-1];
        char sj=s[j];
        while(i!=-1 and sj!=s[i+k+1]){
            if(sj<s[i+k+1]) k=j-i-1;
            i=f[i];
        }
        if(sj!=s[i+k+1]){
            if(sj<s[k]) k=j;
            f[j-k]=-1;
        }
        else f[j-k]=i+1;
    }
    return s.substr(k,n/2);
}

void solve(){
    string str;
    cin>>str;
    cout<<booth(str)<<endl;
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}