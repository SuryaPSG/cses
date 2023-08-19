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

ll res=0;
bool issafe(vector<string> &grid,ll r,ll c){
    forl(i,0,c) if(grid[r][i]=='Q') return false;
    forl(i,0,r) if(grid[i][c]=='Q') return false;
    for(ll i=r,j=c;i>=0 and j>=0;i--,j--){
        if(grid[i][j]=='Q') return false;
    }
    for(ll i=r,j=c;i<8 and j>=0;i++,j--){
        if(grid[i][j]=='Q') return false;
    }
    return true;
}
void solve(vector<string> &grid,ll c){
    if(c==8){
        res++;
        return;
    }
    forl(r,0,8){
        if(grid[r][c]=='*') continue;
        if(issafe(grid,r,c)){
            grid[r][c]='Q';
            solve(grid,c+1);
            grid[r][c]='.';
        }
    }
}

void solve(){
    vector<string> vec(8);
    forl(i,0,8){
        cin>>vec[i];
    }
    solve(vec,0);
    cout<<res<<endl;
}

int main()
{
    DONTSYNC;
    //TEST
    solve();
    return 0;
}