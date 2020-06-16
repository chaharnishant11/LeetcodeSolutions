class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i=0;
        int j=0;
        int n=pushed.size();
        while(i<n && j<n){
            if(i<n)s.push(pushed[i++]);
            while(!s.empty() && j<n && popped[j]==s.top()){
                s.pop();
                j++;
            }
        }
        return j==n;
    }
};