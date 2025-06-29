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
    ll n;
    cin>>n;
    vector<string> vec(n);
    forl(i,0,n) cin>>vec[i];

    vvi vis(n,vi(n));
    vis[0][0]=1;
    queue<pii> q;
    q.push({0,0});
    bool f=false;
    string res;
    res.pb(vec[0][0]);
    while(!f and !q.empty()){
        ll s=q.size();
        char mn = 'Z';
        vll temp;
        while(s--){
            auto [x,y]=q.front();
            q.pop();
            if(x==n-1 and y==n-1) f=true;
            if(x+1<n and !vis[x+1][y]) {
                temp.pb({x+1,y});
                mn=min(mn,vec[x+1][y]);
                vis[x+1][y]=1;
            }
            if(y+1<n and !vis[x][y+1]) {
                temp.pb({x,y+1});
                mn=min(mn,vec[x][y+1]);
                vis[x][y+1]=1;
            }
        }
        if(f) break;
        res.pb(mn);

        for(auto &[f,s]:temp) if(vec[f][s]==mn) q.push({f,s});
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