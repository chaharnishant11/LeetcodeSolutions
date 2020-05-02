class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0,current=0;
        stack<int> st;
        while(current<height.size()){
            while(!st.empty() && height[st.top()]<height[current]){
                int t=st.top();
                st.pop();
                if(st.empty()) break;
                int distance=current-st.top()-1;
                int bound_height=min(height[current],height[st.top()])-height[t];
                ans+=distance*bound_height;
                cout << height[current] << " " << height[st.top()] << " " << height[t] << " " << ans << endl;
            }
            st.push(current++);
        }
        return ans;
    }
};