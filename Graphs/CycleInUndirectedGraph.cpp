bool helper(vector<int> a[],int i,bool* vis,int p){
    vis[i]=true;
    for(auto j:a[i]){
        if(!vis[j]){
            if(helper(a,j,vis,i)) return true;
        }else if(j!=p) return true;
    }
    return false;
}

bool isCyclic(vector<int> adj[], int V)
{
   // Your code here
   bool vis[V];
   for(int i=0;i<V;i++) vis[i]=false;
   for(int i=0;i<V;i++){
      if(!vis[i]){
          if(helper(adj,i,vis,-1)) return true;
      }
   }
   return false;
   
}