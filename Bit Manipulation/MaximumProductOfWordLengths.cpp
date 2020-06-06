class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),compare);
        vector<int> mask(n,0);
        for(int i=0;i<n;i++){
            for(auto c:words[i]){
                mask[i] |= 1 << (c-'a');
            }
        }
        int maxlen=0;
        for(int i=0;i<n-1;i++){
            int si=words[i].size();
            if(si*si<=maxlen) break;
            for(int j=i+1;j<n;j++){
                int len=words[i].size()*words[j].size();
                if(len<=maxlen) break;
                if((mask[i]&mask[j])==0) maxlen=len;
            }
        }
        return maxlen;
    }
    static bool compare(string a,string b){
        return a.size()>b.size();
    }
};