class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> m;
        int ans=0;
        for(auto a:A){
            for( auto b:B){
                m[a+b]++;
            }
        }
        for(auto c:C){
            for(auto d:D){
                auto i=m.find(0-c-d);
                if(i!=m.end()){
                    ans+=i->second;
                }
            }
        }
        return ans;
    }
};