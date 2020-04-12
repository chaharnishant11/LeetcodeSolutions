class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        int n=stones.size();
        if(n==0) return 0;
        if(n==1) return stones[0];
        for(int i=0;i<n;i++){
            q.push(stones[i]);
        }
        while(q.size()>1){
            int a=q.top();
            q.pop();
            int b=q.top();
            q.pop();
            if(a!=b){
                int c=(a>b)?a-b:b-a;
                q.push(c);
            }else q.push(0);
        }
        return q.top();
    }
};