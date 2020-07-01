// Method 1

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

// Method 2

bool cycle(vector<int> g[],int n,int i,int* c){
    if(c[i]!=-1) return c[i]==1;
    c[i]=0;
    for(auto j:g[i]){
        if(cycle(g,n,j,c)) return true;
    }
    c[i]=1;
    return false;
}

bool isCyclic(vector<int> g[], int V)
{
   // Your code here
   int c[V];
   for(int i=0;i<V;i++) c[i]=-1;
   for(int i=0;i<V;i++){
       if(c[i]==-1 && cycle(g,V,i,c)) return true;
   }
   return false;
}