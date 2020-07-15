bool isoperator(string s){
    if(s.size()>1) return false;
    if(s[0]=='+' || s[0]=='-' || s[0]=='/' || s[0]=='*') return true;
    return false;
}

int Solution::evalRPN(vector<string> &A) {
    stack<int> s;
    for(int i=0;i<A.size();i++){
        if(isoperator(A[i])){
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            if(A[i]=="+") s.push(a+b);
            else if(A[i]=="-") s.push(b-a);
            else if(A[i]=="/") s.push(b/a);
            else if(A[i]=="*") s.push(a*b);
        }else{
            int a=stoi(A[i]);
            s.push(a);
        }
    }
    return (s.empty())?0:s.top();
}
