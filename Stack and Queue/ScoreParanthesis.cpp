class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<string> s;
        for(int i=0;i<S.size();i++){
            if(S[i]=='(') 
                s.push("(");
            else if(S[i]==')' && s.top()=="("){
                s.pop();
                s.push("1");
            }
            else{
                int a= stoi(s.top());
                s.pop();
                while(s.top()!="("){
                        int b=stoi(s.top());
                        s.pop();
                        a=a+b;
                }
                s.pop();
                s.push(to_string(2*a));
            }
        }
        while(s.size()!=1){
            int a=stoi(s.top());
            s.pop();
            int b=stoi(s.top());
            s.pop();
            //cout << a << " " <<  b << endl;
            int c=a+b;
            s.push(to_string(c));
        }
        return stoi(s.top());
    }
};

class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> s;
        s.push(0);
        for(auto c:S){
            if(c=='('){
                s.push(0);
            }else{
                int v=s.top();s.pop();
                int w=s.top();s.pop();
                s.push(w+max(2*v,1));
            }
        }
        return s.top();
    }
};