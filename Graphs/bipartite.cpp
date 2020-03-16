class Solution {
public:
    bool helper(vector<vector<int>> g,int* c,int s){
        c[s]=1;
        queue<int> q;
        q.push(s);
        while(!q.empty()){
            int i=q.front();
            q.pop();
            if(find(g[i].begin(),g[i].end(),i)!=g[i].end()) return false;
            for(auto j:g[i]){
                if(c[j]==-1){
                    c[j]=1-c[i];
                    q.push(j);
                }
                else if(c[j]==c[i]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int colour[n];
        for(int i=0;i<n;i++) colour[i]=-1;
        for(int i=0;i<n;i++){
            if(colour[i]==-1){
                if(!helper(graph,colour,i)) return false;
            }
        }
        
        return true;
    }
};