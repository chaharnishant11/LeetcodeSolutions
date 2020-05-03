class Solution {
public:
    int trapRainWater(vector<vector<int>>& h) {
        int n=h.size();
        int m=h[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        bool vis[n][m];
        memset(vis,false,sizeof(vis));
        for(int i=0;i<n;i++){
            q.push({h[i][0],{i,0}});
            q.push({h[i][m-1],{i,m-1}});
            vis[i][m-1]=true;
            vis[i][0]=true;
        }
        for(int j=1;j<m-1;j++){
            q.push({h[0][j],{0,j}});
            q.push({h[n-1][j],{n-1,j}});
            vis[0][j]=true;
            vis[n-1][j]=true;
        }
        int ans=0;
        int mi=INT_MIN;
        int x[4]={1,-1,0,0};
        int y[4]={0,0,-1,1};
        while(!q.empty()){
            mi=max(mi,q.top().first);
            int i=q.top().second.first;
            int j=q.top().second.second;
            q.pop();
            for(int o=0;o<4;o++){
                int k=i+x[o];
                int l=j+y[o];
                if(k>=0 && k<n && l>=0 && l<m && !vis[k][l]){
                    if(h[k][l]<mi){
                        ans+=(mi-h[k][l]);
                    }
                    q.push({h[k][l],{k,l}});
                    vis[k][l]=true;
                }
            }
        }
        return ans;
    }
};