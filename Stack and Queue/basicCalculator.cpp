class Solution {
public:
    
    int precedence(char a) {
        if(a=='-' or a=='+') return 1;
        if(a=='*' or a=='/') return 2;
        if(a=='^') return 3;
        return 4;
    }
    
    void evaluate(int a, int b, char cur, stack<int> &op) {
                            if(cur=='/') {
                        op.push(b/a);
                    } else if(cur=='*') {
                        op.push(b*a);
                    } else if(cur=='+') {
                        op.push(b+a);
                    } else {
                        op.push(b-a);
                    }
    }
    
    int calculate(string s) {
        stack<char> sign;
        stack<int> op;
        for(int i=0; i<s.length(); i++) {
            if(s[i]==' ') continue;
            else if(s[i]=='(') sign.push(s[i]);
            else if(s[i]==')') {
                while(!sign.empty() && sign.top()!='(') {
                    int a= op.top(); op.pop();
                    int b= op.top(); op.pop();
                    char cur= sign.top(); sign.pop(); 
                    evaluate(a, b, cur, op);
                }
                sign.pop();
            }
            else if(isdigit(s[i])) {
                int num=0;
                while(i<s.length() && isdigit(s[i])) num= num*10 + (s[i++]-'0');
                i--;
                op.push(num);
            }
            else {
                int prec= precedence(s[i]);
                while(!sign.empty() && precedence(sign.top())>=prec) {
                    int a= op.top(); op.pop();
                    int b= op.top(); op.pop();
                    char cur= sign.top(); sign.pop();
                    evaluate(a, b, cur, op);
                }
                sign.push(s[i]);
            }
        }
        while(!sign.empty()) {
                    int a= op.top(); op.pop();
                    int b= op.top(); op.pop();
                    char cur= sign.top(); sign.pop(); 
                    evaluate(a, b, cur, op);
                }
        return op.top();
    }
};
