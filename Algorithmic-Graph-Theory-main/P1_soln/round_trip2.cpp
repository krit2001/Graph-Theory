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
vector<int> ans;
 
bool dfs(unordered_map<int,list<int>> &adj, int sv,unordered_map<int,int>& vis,vector<int> &par,int p){
    vis[sv]=1;
    par[sv]=p;
    for(int i: adj[sv]){
        if(vis[i]==0){
            if(dfs(adj,i,vis,par,sv))return true;
        }
        else if(vis[i]==1){
            ans.push_back(i);
            while(sv!=ans[0]){
                ans.push_back(sv);
                sv=par[sv];
            }
            ans.push_back(i);
            return true;
        }
    }
    vis[sv]=2;
    return false;
}
 
 
 
 
int main()
{  functemp();
   int n,m;
   ans.clear();
   cin >> n>>m; // i based index
   unordered_map<int,list<int>> adj;
   for(int i=0;i<m;i++){
    int a,b;
    cin >> a>>b;
    adj[a].push_back(b);
    // adj[b].push_back(a);
   }
   vector<int> par(n+1,-1);
   unordered_map<int,int> vis;
    for(int i=1;i<=n;i++){
        if((!vis[i])&&dfs(adj,i,vis,par,-1)){
            reverse(ans.begin(),ans.end());
            cout << ans.size()<<endl;
            for(int i=0;i<ans.size();i++)cout << ans[i]<<" ";
            cout <<endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE"<<endl;
    
}
