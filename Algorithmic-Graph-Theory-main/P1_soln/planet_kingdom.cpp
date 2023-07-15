#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds; 
#define ll long long 
#define mod 1000000007;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
void functemp(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
vector<int> ans(1e5+5,-1);
// vector<set<int>> scc(1);
void dfs(int sv,unordered_map<int,list<int>> &adj,vector<bool> &vis,stack<int> &s){
    vis[sv]=true;
    for(int i:adj[sv]){
        if(!vis[i])dfs(i,adj,vis,s);
    }
    s.push(sv);
}
void dfs1( unordered_map<int,list<int>>& adj1,vector<bool> &vis,int sv,int count ){
    vis[sv]=true;
    ans[sv]=count ;
    for(int i:adj1[sv]){
        if(!vis[i])dfs1(adj1,vis,i,count);
    }
}
 
int main()
{  functemp();
     int n,m;
     cin >> n>>m;
     unordered_map<int,list<int>> adj;
     while(m--){
        int a,b;
        cin>> a>>b;
        adj[a].push_back(b);
     }
    //  scc.clear();
    stack<int> s;
    vector<bool> vis(n+1,false);
    for(int i=1;i<=n;i++){
        if(!vis[i])dfs(i,adj,vis,s);
    }
    unordered_map<int,list<int>> adj1;
    for(int i=1;i<=n;i++){
        vis[i]=false;
        for(int j: adj[i]){
            adj1[j].push_back(i);
        }
    }
    int count =0;
    while(!s.empty()){
        int t=s.top();
        s.pop();
        if(!vis[t]){
            count++;
            dfs1(adj1,vis,t,count);
            
        } 
    }
   cout << count<<endl;
   for(int i=1;i<=n;i++)cout << ans[i]<<" ";
}   
 