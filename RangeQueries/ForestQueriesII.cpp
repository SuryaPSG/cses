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
vector<string> a;
class BIT{
    public:
    int n;
    vvl t;
    BIT(){}
    BIT(int n){
        this->n=n;
        t=vvl(n+1,vl(n+1));
    }
    void update(int x,int y,int val){
        for(ll i=x+1;i<=n;i+=i&-i){
            for(ll j=y+1;j<=n;j+=j&-j){
                t[i][j]+=val;
            }
        }
    }
    ll sum(int x,int y){
        ll res=0;
        for(ll i=x+1;i>0;i-=i&-i){
            for(ll j=y+1;j>0;j-=j&-j){
                res+=t[i][j];
            }
        }
        return res;
    }
    ll rangesum(ll x1,ll y1,ll x2,ll y2){
        return sum(x2,y2)-sum(x2,y1-1)-sum(x1-1,y2)+sum(x1-1,y1-1);
    }
};

void solve(){
    ll n,q;
    cin>>n>>q;
    a=vector<string>(n);
    BIT f(n);
    forl(i,0,n){
        cin>>a[i];
        forl(j,0,n) if(a[i][j]=='*') f.update(i,j,1);
    }
    forl(i,0,q){
        ll t;
        cin>>t;
        if(t==1){
            ll x,y;
            cin>>x>>y;
            x--;
            y--;
            f.update(x,y,a[x][y]=='*'?-1:1);
            if(a[x][y]=='*') a[x][y]='.';
            else a[x][y]='*';
        }
        else{
            ll x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2,x1--,y1--,x2--,y2--;
            cout<<f.rangesum(x1,y1,x2,y2)<<endl;
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