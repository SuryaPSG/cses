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
const ll md=1e9+7;


ll dp[5005];
class trie{
    public:
    trie * child[26];
    bool isEnd;
    trie(){
        memset(child,0,sizeof(child));
        isEnd=false;
    }
};

trie *root;

void ins(string str){
    trie *t=root;
    for(char c:str){
        if(!t->child[c-'a']) t->child[c-'a']=new trie();
        t=t->child[c-'a'];
    }
    t->isEnd=true;
}

ll search(string str,ll x){
    trie *t=root;
    ll res=0;
    forl(i,x,str.length()){
        if(!t->child[str[i]-'a']) return res;
        t=t->child[str[i]-'a'];
        if(t->isEnd) res=(res+dp[i+1])%md;
    }
    return res;
}



void solve(){
    root=new trie();
    string str;
    cin>>str;
    ll m,n=str.length();
    cin>>m;
    forl(i,0,m){
        string s;
        cin>>s;
        ins(s);
    }
    dp[n]=1;
    for(ll i=str.length()-1;i>=0;i--) dp[i]=search(str,i);
    cout<<dp[0]<<endl;
}

int main()
{
    DONTSYNC;
    // TEST
    solve();
    return 0;
}