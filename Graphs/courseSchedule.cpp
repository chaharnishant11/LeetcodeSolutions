class Solution {
public:
    bool dfs(vector<int> g[],vector<int>& col,int i){
        if(col[i]!=0){
            return col[i]==1;
        }
        col[i]=-1;
        for(auto j:g[i]){
            if(col[j]==0){
                if(!dfs(g,col,j)) return false;
            }else if(col[j]==-1){
                return false;
            }
        }
        col[i]=1;
        return true;
    }
    
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int> g[n];
        for(int i=0;i<n;i++){
            vector<int> t;
            g[i]=t;
        }
        for(int i=0;i<p.size();i++){
            g[p[i][1]].push_back(p[i][0]);
        }
        vector<int> col(n,0);
        for(int i=0;i<n;i++){
            if(col[i]==0){
                if(!dfs(g,col,i)) return false;
            }
        }
        return true;
    }
};