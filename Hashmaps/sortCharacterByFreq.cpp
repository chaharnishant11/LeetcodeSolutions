class Solution {
public:
    string frequencySort(string s) {
        if(s.size()==0) return "";
        int m[256]={0};
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        priority_queue<pair<int,char>> q;
        for(int i=0;i<256;i++){
            if(m[i]>0){
                char c = i;
                q.push({m[i],c});
            }
        }
        string ans="";
        while(!q.empty()){
            int n=q.top().first;
            char c=q.top().second;
            q.pop();
            for(int i=0;i<n;i++){
                ans+=c;
            }
        }
        return ans;
    }
};