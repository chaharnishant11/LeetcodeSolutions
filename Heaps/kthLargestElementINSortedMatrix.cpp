// Approach 1
class Solution {
public:
    struct Compare{
      bool operator()(pair<int,pair<int,int>> const& a,pair<int,pair<int,int>> const& b){
          return a.first>b.first;
      }  
    };
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        if(n==0) return 0;
        int m=matrix[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,Compare> q;
        for(int i=0;i<n && q.size()<k;i++){
            q.push({matrix[i][0],{i,0}});
        }
        int count=0,ans=0;
        while(!q.empty()){
            auto top=q.top();
            q.pop();
            ans=top.first;
            if(++count==k){
                return ans;
            }
            top.second.second++;
            if(m>top.second.second){
                get<0>(top)=matrix[top.second.first][top.second.second];
                q.push(top);
            }
        }
        return ans;
    }
};

// Approach 2
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        priority_queue<int> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<matrix[i].size();j++){
                if(q.size()<k){
                    q.push(matrix[i][j]);
                }else if(q.top()>matrix[i][j]){
                    q.pop();
                    q.push(matrix[i][j]);
                }
            }
        }
        return q.top();
    }
};