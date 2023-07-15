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
 
 
void make(ll v){// used to make a new independent node 
    par[v]=v;
    sze[v]=1;
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
    par[u]=v;// jiska size chota h usko add kar rha hu hamesha
    sze[v]+=sze[u];
    }
}
// void dfs(vector<pair<ll,pair<ll,ll>>> edges,int sv){
//     vis[sv]=true;
//     for(auto i: edges){
 
//     }
// }
 
int main()
{  functemp();
   ll n,m;
   cin>>n>>m;
//    for(int i=0;i<=n;i++)vis[i]=false;
   vector<pair<ll,pair<ll,ll>>> edges;// so that we can sort accoring to weights
   while(m--){
    ll u,v,w;
    cin>>u>>v>>w;
    edges.push_back({w,{u,v}});
   }
//    dfs(edges,1);
//     for(int i=0;i<=n;i++){
//         if(vis[i]==false)
//         cout << "IMPOSSIBLE"<<endl;
//         return 0;
//     }
    sort(edges.begin(),edges.end());// acc to weight
    for(ll i=1;i<=n;i++)make(i);
    // vector<bool> vis(n+1,false);
    // vis[0]=true;
    // if want can get the total weight of MST 
        ll totalw=0;
        ll count =0;
    for(auto i: edges ){
        ll wt=i.first;
        ll u=i.second.first;
        ll v=i.second.second;
        if(find(u)==find(v))continue;// adding this will create loop
        Union(u,v);
        // cout <<"hi";
        count ++;
        totalw+= wt;
        //MST will be formed through this and can also save it meanwhile
 
    }    
    // for(int i=1;i<=n;i++)if(vis[i]==false){
    //     cout<<"IMPOSSIBLE"<<endl;
    //     return 0;
    // } 
    if (count !=n-1){
        cout << "IMPOSSIBLE"<<endl;
        return 0;
    }
    cout<<totalw<<endl; //EK CONDITOIN YA BE ADD KAR SAKTE HO KI CONNECTED H TOH HI ANSWER HOGA
}