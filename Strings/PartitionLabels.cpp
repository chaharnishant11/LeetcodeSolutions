class Solution {
public:
    vector<int> partitionLabels(string S) {
        int n=S.size();
        vector<int> last(26,0);
        for(int i=0;i<n;i++){
            last[S[i]-'a']=i;
        }
        int temp=0,j=0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            j=max(j,last[S[i]-'a']);
            if(j==i){
                ans.push_back(i-temp+1);
                temp=i+1;
            }
        }
        return ans;
    }
};