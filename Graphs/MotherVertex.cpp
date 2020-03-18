// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
/*
 * Function to find if there is a mother vertex in the given graph 
 * V: number of vertices in the graph
 * adj[]: graph representation
 */
int dfs(vector<int> adj[],int i,bool* vis){
    vis[i]=true;
    for(auto j:adj[i]){
        if(!vis[j]) dfs(adj,j,vis);
    }
} 
 
int findMother(int V, vector<int> adj[]) 
{ 
    // Your code here	
    bool vis[V];
    for(int i=0;i<V;i++){
        vis[i]=false;
    }
    int ans=-1;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(adj,i,vis);
            ans=i;
        } 
    }
    for(int i=0;i<V;i++){
        vis[i]=false;
    }
    dfs(adj,ans,vis);
    for(int i=0;i<V;i++) if(vis[i]==false) ans=-1;
    return ans;
    
} 

// { Driver Code Starts.

int main() 
{ 
    int T;
    cin>>T;
    while(T--){
        int num, edges;
        cin>>num>>edges;
        
        vector<int> adj[num];
        
        int u, v;
        while(edges--){
            cin>>u>>v;
            adj[u].push_back(v);
        }
        
        cout<<findMother(num, adj)<<endl;
    }

	return 0;
}   // } Driver Code Ends