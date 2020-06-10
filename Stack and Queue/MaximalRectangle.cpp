class Solution {
public:
    
    int helper(vector<int>& h){
        int n=h.size();
        int ans=0,i=0;
        stack<int> s;
        s.push(0);
        while(i<=n){
            if(s.empty() || (i!=n && h[s.top()]<=h[i])) s.push(i++);
            else{
                int t=h[s.top()];
                s.pop();
                int j=s.empty()?-1:s.top();
                ans=max(ans,t*(i-j-1));
            }
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        if(n==0) return 0;
        int m=matrix[0].size();
        vector<int> h(m,0);
        int ans=0;
        for(int i=0;i<n;i++){
            stack<int> s;
            for(int j=0;j<m;j++){
                // Calculating Height
                if(matrix[i][j]=='1') h[j]+=1;
                else h[j]=0;
            }
            // Calculating max Area
            int temp=helper(h);
            ans=max(ans,temp);
        }
        return ans;
    }
};