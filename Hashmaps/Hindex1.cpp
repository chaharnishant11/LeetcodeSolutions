class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size()==0) return 0;
        int n=citations.size();
        vector<int> m(n+1,0);
        for(int i=0;i<n;i++){
            if(citations[i]>n){
                m[n]++;
            }else{
                m[citations[i]]++;
            }
        }
        int paper=0;
        for(int i=n;i>=0;i--){
            paper+=m[i];
            if(paper>=i) return i;
        }
        return paper;
    }
};