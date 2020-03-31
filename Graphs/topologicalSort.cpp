int* topoSort(int V, vector<int> adj[]) {
    // Your code here
    int id[V]={0};
    for(int i=0;i<V;i++){
        for(auto j:adj[i]){
            id[j]++;
        }
    }
    queue<int> q;
    for(int i=0;i<V;i++){
        if(id[i]==0){
            q.push(i);
        }
    }
    static int ans[100];
    int c=0;
    while(!q.empty()){
        int f=q.front();
        q.pop();
        vis[f]=true;
        ans[c]=f;
        for( auto i: adj[f]){
            id[i]--;
            if(id[i]==0) q.push(i);
        }
        c++;
    }
    return ans;
}