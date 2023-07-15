#include <bits/stdc++.h>
#define ll long long 
#define mod 1000000007;
using namespace std;
void functemp(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
// USE BASIC DSU FUNCTION AND WILL GIVE NLOGN COMPLEXITY
 const ll N=1e5+5; // const is very important
ll par[N];
ll sze[N];
multiset<ll> s;
 
 
void make(ll v){// used to make a new independent node 
    par[v]=v;
    sze[v]=1;
    s.insert(1);
}
 
ll find(ll v){// find ultimate parent
//improve by path compression
    if(par[v]==v)return v;
    //path compression
    else return par[v]=find(par[v]);
 
}
 
 
void Union(ll v,ll u){// do union of two node 
// isko improve size and rank do sa kar sakte h rank m depth sa karta h and size m component k size sa
    v=find(v);
    u=find(u);
    // m hamesha a ko bade size ka man rha hu
    if(v!=u){
    if(sze[v]<sze[u])swap(v,u);
    s.erase(s.find(sze[v]));
    s.erase(s.find(sze[u]));
    s.insert(sze[u]+sze[v]);
    par[u]=v;// jiska size chota h usko add kar rha hu hamesha
    sze[v]+=sze[u];
    }
}
 
int main()
{  functemp();
   ll n,m;
   cin>>n>>m;
   s.clear();
   for(ll i=1;i<=n;i++)make(i);
   while(m--){
    ll a,b;cin >> a>>b;
    // if(find(a)==find(b))co       ntinue;
    Union(a,b);
    cout << s.size()<<" ";
    int maxx=*(--s.end());
    cout << maxx<<endl;
 
 
   }
    
  
}