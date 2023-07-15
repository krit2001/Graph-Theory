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
 
// bool dfs(unordered_map<int,list<int>> &adj, int sv,unordered_map<int,int>& vis,vector<int> &par,int p){
//     vis[sv]=1;
//     par[sv]=p;
//     for(int i: adj[sv]){
//         if(vis[i]==0){
//             if(dfs(adj,i,vis,par,sv))return true;
//         }
//         else if(vis[i]==1){
//             ans.push_back(i);
//             while(sv!=ans[0]){
//                 ans.push_back(sv);
//                 sv=par[sv];
//             }
//             ans.push_back(i);
//             return true;
//         }
//     }
//     vis[sv]=2;
//     return false;
// }
 
 
 
 
int main()
{  functemp();
   ll n,m;
//    dis.clear();
   cin >> n>>m; // i based index
   unordered_map<ll,list<pair<ll,ll>>> adj;
   for(ll i=0;i<m;i++){
    ll a,b,w;
    cin >> a>>b>>w;
    adj[a].push_back({b,w});
    // adj[b].push_back(a);
   }
vector<ll> dis(n+1,1e18);
//    vector<ll> par(n+1,-1);
//    unordered_map<ll,ll> vis;
// vector<bool> vis(n+1,false); 
    // for(ll i=1;i<=n;i++){
        // if((!vis[i])&&dfs(adj,i,vis,par,-1)){
        //     reverse(ans.begin(),ans.end());
        //     cout << ans.size()<<endl;
        //     for(ll i=0;i<ans.size();i++)cout << ans[i]<<" ";
        //     cout <<endl;
        //     return 0;
        // }
    // }
    // cout << "IMPOSSIBLE"<<endl;
        priority_queue<pair<ll,ll> , vector<pair<ll,ll>> , greater<pair<ll,ll>> > pq;
 
    pq.push({0,1});
    dis[1]=0;
    
    while(!pq.empty()){
        ll curr=pq.top().second;
        ll currd=pq.top().first;
        pq.pop();
       if(dis[curr]<currd)continue;
        for(pair<ll,ll> p: adj[curr]){
            ll child =p.first;
            ll childd=p.second;
            // if(child==par[curr])continue;
            if(currd+childd< dis[child] ){
                // par[child]=curr;
                    dis[child]=currd+childd;
                    pq.push({dis[child],child});
            }
        }
    }
    for(ll i=1;i<=n;i++)cout << dis[i]<<" ";
    cout << endl;
 
 
 
 
 
 
}