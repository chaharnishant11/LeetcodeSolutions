class Solution {
public:
    vector<int>next_greater(vector<int>vec){
        int n=vec.size();
        vector<int>greater(n,-1);
        map<int,int>mp;
        set<int>st;
        for(int i=n-1;i>=0;i--){
            auto it=st.lower_bound(vec[i]);
            if(it==st.end()){
                greater[i]=i;
            }
            else{
                greater[i]=mp[*it];
            }
            st.insert(vec[i]);
            mp[vec[i]]=i;
        }
        for(int i=0;i<n;i++){
            cout<<greater[i]<<" ";
        }
        cout<<endl;
        return greater;
    }
    
    vector<int>next_smaller(vector<int>vec){
        int n=vec.size();
        vector<int>smaller(n,-1);
        set<pair<int,int>>st;
        for(int i=n-1;i>=0;i--){
            // auto it=st.lower_bound({});
            if(st.size()==0){
                smaller[i]=i;
            }
            else{
                auto it=st.lower_bound({-vec[i],i});
                if(it==st.end()){
                    smaller[i]=i;
                }
                else{
                    auto p=*it;
                    smaller[i]=p.second;
                }
            }
            st.insert({-vec[i],i});
        }
        for(int i=0;i<n;i++){
            cout<<smaller[i]<<" ";
        }
        cout<<endl;
        return smaller;
    }
    
    int oddEvenJumps(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(2,0));
        vector<int>big=next_greater(arr);
        vector<int>small=next_smaller(arr);
        
        for(int i=0;i<n;i++){
            dp[i][1]=1;
        }
        for(int i=0;i<n;i++){
            int next_big=big[i];
            if(next_big!=i){
                dp[next_big][0]+=dp[i][1];
            }
            
            int next_small=small[i];
            if(next_small!=i){
                dp[next_small][1]+=dp[i][0];                
            }
        }
        
        int ans=0;
        ans+=dp[n-1][0]+dp[n-1][1];
        return ans;
    }
};
