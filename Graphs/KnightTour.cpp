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

ll dir[8][2]={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};

ll g[8][8];

ll degree(ll x,ll y){
    ll s=0;
    forl(i,0,8){
        int nx=x+dir[i][0];
        int ny=y+dir[i][1];
        if(nx>=0 and ny>=0 and nx<8 and ny<8 and g[nx][ny]==0) s++;
    }
    return s;
}
void solve(int x,int y,int m){
    g[x][y]=m;
    if(m==64){
        forl(i,0,8){
            forl(j,0,8) cout<<g[i][j]<<" ";
            cout<<endl;
        }
        exit(0);
    }
    vvl deg;
    forl(i,0,8){
        int nx=x+dir[i][0];
        int ny=y+dir[i][1];
        if(nx>=0 and ny>=0 and nx<8 and ny<8 and g[nx][ny]==0){
            int d= degree(nx,ny);
            deg.pb({d,nx,ny});
        }
    }
    sort(all(deg));
    for(auto v:deg){
        int nx=v[1],ny=v[2];
        solve(nx,ny,m+1);
    }
    g[x][y]=0;
}

void solve(){
    ll x,y;
    cin>>y>>x;
    memset(g,0,sizeof(g));
    x--;
    y--;
    solve(x,y,1);
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}