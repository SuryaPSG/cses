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
typedef pair<char,int> pci;

int mp[26]={0};

bool issf(int c){
    int mx=0,t=0;
    for(int i=0;i<26;i++){
        if(mp[mx]<mp[i]) mx=i;
        t+=mp[i];
    }
    return mp[mx]<=(t+1)/2 and mp[c]<=t/2;
}

void solve(){
    string s;
    cin>>s;
    int n=s.size();
    
    int mx=0;
    for(char c:s) mp[c-'A']++;
    int last=26;
    string res;
    forl(i,0,n){
        bool f = false;
        for(int c=0;c<26 and !f;c++){
            if(mp[c]==0 or last==c) continue;
            mp[c]--;
            if(issf(c)){
                res.push_back((char)(c+'A'));
                f=true;
                last=c;
            }
            else mp[c]++;
        }
        if(!f){
            cout<<"-1"<<endl;
            return;
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