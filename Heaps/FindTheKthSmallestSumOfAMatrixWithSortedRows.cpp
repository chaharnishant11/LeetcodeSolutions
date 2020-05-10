class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>, greater<pair<int,vector<int>>>> q;
        vector<int> temp(n,0);
        int s=0;
        for(int i=0;i<n;i++){
            s+=mat[i][0];
        }
        map<vector<int>, int> vis; 
        q.push({s,temp});
        vis[temp]=1;
        int x=0;
        while(!q.empty()){
            auto p=q.top();
            q.pop();
            temp=p.second;
            x++;
            if(x==k){
                return p.first;
            }
            for(int i=0;i<n;i++){
                s=p.first;
                temp=p.second;
                int j=temp[i];
                s-=mat[i][j];
                if(j+1<m){
                    s+=mat[i][j+1];
                    temp[i]=j+1;
                }
                if(j+1<m && vis.find(temp)==vis.end()){
                    vis[temp]=1;
                    q.push({s,temp});
                }
            }
        }
        return 0;
    }
};