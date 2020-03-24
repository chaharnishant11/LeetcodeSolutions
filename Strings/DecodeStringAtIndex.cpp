class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long long size=0;
        for(int i=0;i<S.size();i++){
            if(isdigit(S[i])){
                size*=S[i]-'0';
            }else{
                size++;
            }
        }
        for(int i=S.size()-1;i>=0;i--){
            K=K%size;
            if(K==0 && isalpha(S[i])){
                return (string)""+S[i];
            }
            if(isdigit(S[i]))
                size/=S[i]-'0';
            else size--;
        }
        return "";
    }
};