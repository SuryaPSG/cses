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
    ll n,a,b;
    cin>>n>>a>>b;
    if(a==0 && b==0){
        cout<<"YES"<<endl;
        forl(i,1,n+1) cout<<i<<" ";
        cout<<endl;
        forl(i,1,n+1) cout<<i<<" ";
        cout<<endl;
        return;
    }
    if(a+b>n or (a==0 || b==0)){
        cout<<"NO"<<endl;
        return;
    }
    int s= n-(a+b);
    cout<<"YES"<<endl;
    vl p,q;
    forl(i,1,s+1){
        p.push_back(i);
        q.push_back(i);
    }
    forl(i,1,b+1){
        p.push_back(s+i);
        q.push_back(s+i+a);
    }
    forl(i,1,a+1){
        p.push_back(s+i+b);
        q.push_back(s+i);
    }
    for(ll i:p) cout<<i<<" ";
    cout<<endl;
    for(ll i:q) cout<<i<<" ";
    cout<<endl;
}

int main()
{
    DONTSYNC;
    TEST
    solve();
    return 0;
}