class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        if(n==0) return 0;
        if(n==1) return heights[0];
        stack<int> s;
        s.push(0);
        int i=0;
        int ans=0;
        while(i<=n){
            if(s.empty() || (i!=n && heights[i]>=heights[s.top()])) s.push(i++);
            else{
                int h=heights[s.top()];
                s.pop();
                int j=s.empty()?-1:s.top();
                ans=max(ans,h*(i-j-1));
            }
        }
        return ans;
    }
};