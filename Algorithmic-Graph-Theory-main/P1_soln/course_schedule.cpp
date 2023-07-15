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
int main()
{  functemp();
     int n,m;
     cin >> n>>m;
     unordered_map<int,list<int>> adj;
     vector<int > inarray(n+1,0);
     vector<int> ans;
     while(m--){
        int a,b;
        cin>> a>>b;
        adj[a].push_back(b);
        inarray[b]++;
     }
 
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(inarray[i]==0)q.push(i);
    }
    vector<bool> vis(n+1,false);
    while(!q.empty()){
        int curr =q.front();
        q.pop();
        if(vis[curr])continue;
        ans.push_back(curr);
        vis[curr]=true;
        for(auto i: adj[curr]){
            if(!vis[i]){
                inarray[i]--;
                if(inarray[i]==0)q.push(i);
            }
        }
    }
    if(ans.size()!=n){
        cout << "IMPOSSIBLE"<<endl;
        return 0;
    }
    for(int i: ans)cout << i<<" ";
    cout << endl;
 
 
 
}