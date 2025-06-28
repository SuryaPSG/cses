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

int dir[8][2] = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};

void solve(){
    ll n;
    cin>>n;
    vvl res(n,vl(n,INT_MAX));
    queue<pll> q;
    q.push({0,0});
    res[0][0]=0;
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        for(int i=0;i<8;i++){
            int nx=x+dir[i][0],ny=y+dir[i][1];
            if(nx>=0 and ny>=0 and nx<n and ny<n and res[nx][ny]>res[x][y]+1){
                res[nx][ny]=res[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
    forl(i,0,n){
        forl(j,0,n) cout<<res[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    DONTSYNC;
    //TEST
    solve();
    return 0;
}