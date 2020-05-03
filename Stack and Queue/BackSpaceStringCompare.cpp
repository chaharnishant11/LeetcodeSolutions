class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s;
        for(int i=0;i<S.size();i++){
            if(S[i]=='#' && !s.empty()){
                s.pop();
            }else if(S[i]!='#'){
                s.push(S[i]);
            }
        }
        S="";
        while(!s.empty()){
            S+=s.top();
            s.pop();
        }
        for(int i=0;i<T.size();i++){
            if(T[i]=='#' && !s.empty()){
                s.pop();
            }else if(T[i]!='#'){
                s.push(T[i]);
            }
        }
        T="";
        while(!s.empty()){
            T+=s.top();
            s.pop();
        }
        //cout << S << " " << T;
        return S==T;
    }
};