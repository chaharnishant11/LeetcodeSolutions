class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if(n==0) return {};
        int m=matrix[0].size();
        if(m==0) return {};
        int rs=0,re=n-1,cs=0,ce=m-1;
        vector<int> ans;
        int dim=(n)*(m);
        int k=0;
        while(rs<=re && cs<=ce){
            for(int i=cs;i<=ce && k<dim;i++,k++){
                ans.push_back(matrix[rs][i]);
            }
            if(k==dim) break;
            rs++;
            for(int i=rs;i<=re && k<dim;i++,k++){
                ans.push_back(matrix[i][ce]);
            }
            if(k>dim) break;
            ce--;
            for(int i=ce;i>=cs && k<dim;i--,k++){
                ans.push_back(matrix[re][i]);
            }
            if(k>dim) break;
            re--;
            for(int i=re;i>=rs && k<dim;i--,k++){
                ans.push_back(matrix[i][cs]);
            }
            if(k>dim) break;
            cs++;
        }
        return ans;
    }
};