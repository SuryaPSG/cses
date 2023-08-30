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
ll dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
string str="DRUL";
void solve(){
    cin>>m>>n;
    vector<string> vec(m);
    forl(i,0,m) cin>>vec[i];

    ll sx=-1,sy=-1;
    queue<pll> Q;
    forl(i,0,m){
        forl(j,0,n){
            if(vec[i][j]=='A') sx=i,sy=j;
            if(vec[i][j]=='M')  Q.push({i,j});
        }
    }

    int path[m][n];
    memset(path,-1,sizeof(path));
    
    Q.push({sx,sy});
    while (!Q.empty())
    {
        pll p=Q.front();
        Q.pop();
        ll x=p.fi,y=p.se;
        if(vec[x][y]=='A' and (x==0 || y==0 || x==m-1 || y==n-1)){
            string res;
            while(x!=sx or y!=sy){
                if(path[x][y]==-1) break;
                ll l=path[x][y];
                res.pb(str[l]);
                x=x-dir[l][0];
                y=y-dir[l][1];
            }
            reverse(all(res));
            cout<<"YES"<<endl;
            cout<<res.size()<<endl;
            cout<<res<<endl;
            return;
        }
        forl(i,0,4){
            ll nx=x+dir[i][0],ny=y+dir[i][1];
            if(nx>=0 and ny>=0 and nx<m and ny<n and vec[nx][ny]=='.'){
                vec[nx][ny]=vec[x][y];
                Q.push({nx,ny});
                if(vec[nx][ny]=='A')path[nx][ny]=i;
            }
        }
    }
    cout<<"NO"<<endl;
    return;
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}