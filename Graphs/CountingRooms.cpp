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
ll m,n;
ll dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
void dfs(vector<string> &vec,ll x,ll y){
    if(x<0 or y<0 or x>=m or y>=n or vec[x][y]!='.') return;
    vec[x][y]='#';
    forl(i,0,4){
        ll nx=x+dir[i][0],ny=y+dir[i][1];
        dfs(vec,nx,ny);
    }
}

void solve(){
    cin>>m>>n;
    vector<string> vec(m);
    forl(i,0,m) cin>>vec[i];
    ll res=0;
    forl(i,0,m){
        forl(j,0,n){
            if(vec[i][j]=='.'){
                dfs(vec,i,j);
                res++;
            }
        }
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