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

void solve(){
    string str;
    cin>>str;
    unordered_map<char,ll> mp;
    ll o=0LL;
    char oc=' ';
    for(char c:str){
        mp[c]++;
        if(mp[c]%2){
            o++;
        }
        else o--;
    }
    if(o>1){
        cout<<"NO SOLUTION"<<endl;
        return;
    }
    string res;
    for(auto p:mp){
        res+=string(p.second/2,p.first);
        if(p.second&1) oc=p.first;
    }
    string right=res;
    reverse(all(right));
    if(o) res.pb(oc);
    res+=right;
    cout<<res<<endl;
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}